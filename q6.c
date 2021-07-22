/*NAME-SNEH SUMAN
  ROLL NO-2019337    OS*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

   
    sem_t dine;
    sem_t forks[5];//declaring number of forks 
   void * philosopher(void * num)
   {

    int phil=*(int *)num;
    int right = (phil + 1) %5;//fork on right side of the dining table
    int left = (phil +5) % 5;//fork on left side of the dining table

    sem_wait(&dine);

    sem_wait(&forks[phil]);
    sem_wait(&forks[(phil+1)%5]);
    printf("Philosopher %d receives forks %d\n", phil, right);
    printf("Philosopher %d receives forks %d\n", phil, left);
     printf("\nPhilosopher %d is putting the forkss down ",phil);

    printf(" %d %d\n", right, left);
    sleep(2);


    sem_post(&forks[(phil+1)%5]);
    sem_post(&forks[phil]);
    sem_post(&dine);
    }
    
    int main()
    {
        int i;
        int ae[5];
        int arr[5];
        pthread_t tid[5];

        sem_init(&dine,0,4);

        i=0;
        while (i<5) {
            sem_init(&forks[i],0,1 );
            i++;
        };

        i=0;
        while (i<5) {
            ae[i]=arr[i];
            ae[i]=i;
            pthread_create(&tid[i],NULL,philosopher,(void *)&ae[i]);//creating the thread
            i++;
        }
        i=0;
        while (i<5) {
            pthread_join(tid[i],NULL);//joining the threads
            i++;
        }
    }



   