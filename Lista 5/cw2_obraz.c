#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 256

int main(int argc, char *argv[]) {
  //int main() {

  pid_t PID_num;

  int pipe_fd[2];
  int descriptor;
  int temp;

  char buf[BUF_SIZE];
  
  //char image_name[32];
  
  if(pipe(pipe_fd) < 0) {

    fprintf(stderr, "ERROR:  Pipe error!\n");
    return 1;
  }

  PID_num = fork();

  if(PID_num == 0) {
    printf("Child process\n");
    close(pipe_fd[1]);
    //close(0);
    //dup(pipe_fd[0]);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[0]);

    execlp("display", "display", "-", NULL);
  }
  else {
    printf("Parent process\n");
    printf("PID_num = %d\n", PID_num);
    close(pipe_fd[0]);
    //printf("Image name: (PNG or JPG)\n");
    //scanf("%s", image_name);

    //if((descriptor = open(image_name, O_RDONLY)) < 0) {
    if((descriptor = open(argv[1], O_RDONLY)) < 0) {

      fprintf(stderr, "ERROR: file not open!\n");
      return 2;
    }

    while((temp = read(descriptor, &buf, BUF_SIZE)) > 0) {

      if(write(pipe_fd[1], &buf, temp) < 0) {
	fprintf(stderr, "ERROR: Pipe writing error!\n");
	return 3;
      }
    }
    close(descriptor);
  }
}
