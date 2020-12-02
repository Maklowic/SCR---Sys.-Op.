#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define path_FIFO "fifo" // ścieżka potoku
#define MAX_BUFFER 256 // rozmiar max buforu

/*
	Wywołanie ./<nazwa programu> <arg1> <arg2> <arg3> <arg4> <arg5> ...

	Śledzenie potoku: 
						tail -c +1 -f <ścieżka potoku>(w tyma wypadku "fifo")
 
*/


int main(int argc, char *argv[]) {

	int potok_fd; 			// fd potoku
	int descriptor[100]; 	// tablica na deskryptory
	int temp; 			// pomoc przy czytaniu i pisaniu do potoku
 	char buf[MAX_BUFFER];	// bufor

	
	mkfifo(path_FIFO, 0666); // 0666 - write and read only

	potok_fd = open(path_FIFO, O_WRONLY); // otwieranbie potoku tylko do czytania
	
	for(int j=1; j < argc; j++)  // dla ilości argumentów
	{
		descriptor[j-1] = open(argv[j], O_RDONLY); // otwieranie pliku tylko do czytania
		if(descriptor[j-1] < 0)			// sprawdzenie czy otwarto plik
			puts("Nie udalo sie otworzyc pliku"); //error message

		// zapisanie do potoku
		while ((temp=read(descriptor[j-1], buf, MAX_BUFFER)) > 0)
		{
			write(potok_fd, buf, temp);
		}
	}
	close(potok_fd);
	return 0;
}
