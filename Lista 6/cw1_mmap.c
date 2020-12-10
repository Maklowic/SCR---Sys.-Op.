#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100

int main(int argc, char** argv) {

  char in_file_name[MAX_FILE_NAME]; //name of the input file to read from
  int fd; // file descriptor
  int out_fd; // out file descriptor
  struct stat sb; // structure with file status
  char *file_in_memory; // mapped area


  while(1) {

    printf("Input file name (to quit type 'q'): ");
    scanf("%s", in_file_name);
    // openning an input file with read write premission only for owner
    fd = open(in_file_name, O_RDWR, S_IRUSR | S_IWUSR);

    // break
    if (in_file_name[0] == 'q') {
      printf("QUIT!\n");
      return 0;
    }
    
    // Error message
    if(fd < 0) {
      fprintf(stderr, "ERROR: Couldn't open a file called %s!\n", in_file_name);
      return -1;
    }


    // checks if everything is alright with our file descriptor
    if (fstat(fd, &sb) < 0) {
      fprintf(stderr, "ERROR: File size problem!\n");
      return -2;
    }

    // opening an out file descriptor  where we want to copy everything from in file
    out_fd = open("ffiillee.txt", O_RDWR | O_CREAT);

    // change up length od the file "ffiillee.txt" according to size of the input file of lenght stored in structure
    truncate("ffiillee.txt", sb.st_size);
    
    // mapping by mmap with (address, file length, permission to read and write, map sharing with system, out file descriptor, translation)
    file_in_memory =    mmap(NULL,    sb.st_size,  PROT_READ | PROT_WRITE,       MAP_SHARED,              out_fd,              0);

    // reading from fd number of bits according to length of st_size. Then writting to mapped file  
    read(fd, file_in_memory, sb.st_size);

    // update/sync mapped file
    msync(file_in_memory, sb.st_size, MS_SYNC);

    // clearing mapped area from virtual memory
    munmap(file_in_memory, sb.st_size);

    // closing input file descritor
    close(fd);
  }
}
