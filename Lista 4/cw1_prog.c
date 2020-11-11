#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

/* bez usleep znajduje się na górze top
   z usleep znajduje się na dole
   zmiana odświeżania top za pomocą flagi -d
*/
void main() {
    int i;
    //for(int j=0; j<4; j++) {
    while(1){
        i++;
        printf("%i \n", i);
        usleep(100000); // 100 ms
    }
}