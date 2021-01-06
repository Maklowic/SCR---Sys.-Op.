#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 7

void *Hello_SCR_thread(void *THREAD_ID) {

    printf("Hello SCR. Written by thread %ld\n", THREAD_ID);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  // ilosc watkow
  int number_of_threads = NUM_THREADS;

  pthread_t t_id[number_of_threads];
    int status;
	// zastosowany long, gdyz int był za krotki przy rzutowaniu na void
    for(long i = 0; i < number_of_threads; ++i) {

      status = pthread_create(&t_id[i], NULL, Hello_SCR_thread, (void *) i);

        if(status) {
            fprintf(stderr, "ERROR: Faild creating a thread!");
        }
    }

    for(int j = 0; j < number_of_threads; ++j) {

        pthread_join(t_id[j], NULL);
    }

    pthread_exit(NULL);
}
