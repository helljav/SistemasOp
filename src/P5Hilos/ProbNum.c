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
int iteraciones;

int main(int argc, char **argv[]){
    srand(time(NULL));
    iteraciones = atoi(argv[1]);//Se carga el numero que resive como parametro desde que se ejecuta    
    pthread_t t_maestros[3];
    int retrasos_ale[5];//5 representa el numero de hilos, se debe de modificar la implementacion para esta practica
    //llenamos el arreglo con los numeros aleatorios
    for (int i = 0; i < 5; i++){
        num_ale[i] = rand()%1000000%
    }
    
   
}


void * t_control_total(void *arg){
    // Casteo para obtener el tid del hilo
    int tid = *((int *)(&arg));
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
}