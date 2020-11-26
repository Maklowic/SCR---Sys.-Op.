#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER 64


int main(int argc, char *argv[]) {
    
    pid_t PID_num;
    int pipe_fd[2];

    char buf[MAX_BUFFER];


    pipe(pipe_fd);

    PID_num = fork();

    if(PID_num < 0) {
        
        fprintf(stderr, "ERROR:  Pipe error!\n");
        return 1;
    }


    if (PID_num == 0) {
        printf("Child process\n");
        while (read(pipe_fd[0], buf, MAX_BUFFER)) {
            if (buf[MAX_BUFFER - 1] == 0) {
                break;
            }
            buf[MAX_BUFFER - 1] = '\0';
            printf("#%s#\n", buf);
        }
    }
    else {
        printf("Parent process\n");
        printf("PID_num = %n", PID_num);
        FILE *f = fopen(argv[1], "r");

        while (fgets(buf, MAX_BUFFER - 1, f)) {
            buf[MAX_BUFFER - 1] = 1;
            write(pipe_fd[1], buf, MAX_BUFFER);
        }

        buf[MAX_BUFFER - 1] = 0;
        write(pipe_fd[1], buf, MAX_BUFFER);

        fclose(f);
    };
}