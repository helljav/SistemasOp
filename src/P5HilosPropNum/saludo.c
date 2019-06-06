#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//Prototipos
void * Saludo(void*);

int num_ale[5];

int main(int argc, char **argv){
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        num_ale[i] = rand() % 1000000;
    }
    
    pthread_t t1,t2,t3,t4,t5;

    pthread_create(&t1, NULL, Saludo, (void*)0);
    pthread_create(&t2, NULL, Saludo, (void*)1);
    pthread_create(&t3, NULL, Saludo, (void*)2);
    pthread_create(&t4, NULL, Saludo, (void*)3);
    pthread_create(&t5, NULL, Saludo, (void*)4);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_join(t5,NULL);
}


void * Saludo(void *arg){
    int tid = *((int *)(&arg));
    int retraso = num_ale[tid];
    float tiempo_r = (float)num_ale[tid] / 1000000;
    printf("\tHola soy el hilo con TID = %d\n", tid);
    usleep(retraso);
    printf("\t%d: Termino mi ejecucion despues de %1.2f segundos\n", tid,tiempo_r);
    pthread_exit(NULL);
}