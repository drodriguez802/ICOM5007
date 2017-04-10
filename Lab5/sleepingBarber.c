/*Daniel Rodriguez Garcia 802-12-6560*/

#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <stdlib.h>

sem_t chairs, client, barber;
int freeChairs;
pthread_t tid;

void * barberMain() {
  while (1) {
    sem_wait( & client);
    sem_wait( & chairs);
    freeChairs++;
    sem_post( & barber);
    sem_post( & chairs);
    printf("Barber working, freeChairs: %d\n", freeChairs);
  }

}

void * clientMain() {
  while (1) {
    sem_wait( & chairs);
    if (freeChairs > 0) {
      freeChairs--;
      sem_post( & client);
      sem_post( & chairs);
      sem_wait( & barber);
      printf("Customers waiting: %d \n", freeChairs);
    } else {
      sem_post( & chairs);
      printf("Customer left\n");
    }
  }
}

int main(int argc, char * argv[]) {
  freeChairs = atoi(argv[1]);

  int i;

  sem_init( & chairs, i, 1);
  sem_init( & barber, i, 0);
  sem_init( & client, i, 0);

  for (i = 0; i < 1; i++)
    pthread_create( & tid, NULL, barberMain, NULL);

  for (i = 0; i < freeChairs; i++)
    pthread_create( & tid, NULL, clientMain, NULL);
  pthread_join(tid, NULL);
}
