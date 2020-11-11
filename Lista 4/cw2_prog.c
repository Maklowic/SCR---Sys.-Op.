#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int stop = 0;


void signal_handler(int signal_number){
	printf("Sygnał numer: ");
	if(signal_number==14){
		printf("%i \n", signal_number);
        printf("Nazwa: SIGALRM\n");
		printf("Akcja: (a) wyświetlenie komunikatu i zakończenie pracy programu \n");
		exit(0);
	}
	if(signal_number==15){
        printf("%i \n", signal_number);
        printf("Nazwa: SIGTERM\n");
		printf("Akcja: (b) wyświetlenie komunikatu i powrót do wykonywania programu\n");
	}
	if(signal_number==10){
        printf("%i \n", signal_number);
        printf("Nazwa: SIGUSR1\n");
		printf("Akcja: (c) wstrzymywanie odebrania sygnału na 1000 iteracji w pętli, i następnie wznowienie odebrania sygnału\n");
		stop = 1;
	}	
}

// ======================-<| MAIN |>-=======================

int main(){

	signal(SIGUSR2,SIG_IGN);
	int i=0;
    int tmp_counter = 0;
	while(1){

		i++;
		printf("%i \n",i);
        // 100 ms
		usleep(100000);	

		if(stop == 0){
			signal(SIGALRM,signal_handler);
			signal(SIGTERM,signal_handler);
			signal(SIGUSR1,signal_handler);
		}
		if(stop == 1){
			signal(SIGALRM,SIG_IGN);
			signal(SIGTERM,SIG_IGN);
			signal(SIGUSR1,SIG_IGN);

			if(tmp_counter < i)
                //1000 iteracji
				tmp_counter = i + 1000;
                
			if(i==tmp_counter){
				printf("Zrobiono 1000 iteracji\n");
                printf("Powrót działania sygnałów\n");
				stop = 0;
			}
		}
	}
	return 0;
}
