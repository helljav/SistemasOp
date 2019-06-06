#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

//EN ESTA PARTE HAGO LOS LLAMADOS DE LOS PROTOTIPOS QUE VOY A UTILIZAR PARA QUE C LOS PUEDA
//RECONOCER

void * t_control_total(void *arg);
void * t_perfectos(void *arg);
void * t_fuertes(void *arg);
void * t_primos(void *arg);
void crearArr(int );
int iteraciones;
int *arrNum;

int main(int argc, char const *argv[]){
    srand(time(NULL));
    iteraciones = atoi(argv[1]);//Se carga el numero que recibe como parametro desde que se ejecuta
    crearArr(iteraciones);
    //Creacion de hilos maestros 
    pthread_t t_maestros[3];
    for (long i = 0; i < 3; i++){
        pthread_create(&t_maestros[i],NULL,t_control_total,(void *)i);
    }
    for (long i = 0; i < 3; i++){
        pthread_join(t_maestros[i],NULL);
    }
    
    
    
   
}

void crearArr(int iteraciones){
    arrNum = (int *)malloc(iteraciones*sizeof(int));
    for (int i = 1; i < iteraciones+1; i++){
        arrNum[i]=i;
        printf("%d\n", arrNum[i]);
    }
}


void * t_control_total(void *arg){
    // Casteo para obtener el tid del hilo
    int tid = *((int *)(&arg));
    printf("Hola soy el hilo con el tid: %d", tid);

    int numHilos;//numero de hilos bebes

    pthread_exit(NULL);
}

void * t_perfectos(void *arg){
    // En python3
    // def esPerfecto(num):	
    // sumatorio=0
    // for i in range(1,num):
    //         if num%i==0:
    //             sumatorio=sumatorio+i
    // if sumatorio==num:
    //     return True
    // else:
    //     return False
    pthread_exit(NULL);
}
void * t_primos(void *arg){
    // En python3
    // def esPrimo(num):
    // if num < 2:     
    //     return False
    // for i in range(2, num):  
    //     if num % i == 0:    
    //         return False
    // return True 
    pthread_exit(NULL);
}