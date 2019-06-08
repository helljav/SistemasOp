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

#define N_Maestros 3
#define N_Esclavos  100
int iteraciones;
int contPerfectos[N_Esclavos];
int contDuros [N_Esclavos];
int contPrimos [N_Esclavos];
int resultadoMaestros[N_Maestros];



int main(int argc, char const *argv[]){
    srand(time(NULL));
    iteraciones = atoi(argv[1]);//Se carga el numero que recibe como parametro desde que se ejecuta
   
    //Creacion de hilos maestros 
    pthread_t t_maestros[N_Maestros];
    for (long i = 0; i < N_Maestros; i++){
        pthread_create(&t_maestros[i],NULL,t_control_total,(void *)i);
    }
    for (long i = 0; i < N_Maestros; i++){
        pthread_join(t_maestros[i],NULL);
    }  
   
}




void * t_control_total(void *arg){
    // Casteo para obtener el tid del hilo
    int tid = *((int *)(&arg));
    
    printf("Hola soy el maestro con el tid: %d\n",tid);
    if(tid==0){
            printf("TiD-0: Mitrabajo es buscar numeros perfectos\n");
            printf("TiD-0: Numero de hijos lanzados: %d\n", N_Esclavos);
            pthread_t t_esclavos[N_Esclavos];
            int total_perfc=0;
            for (long i = 0; i < N_Esclavos; i++){
                pthread_create(&t_esclavos[i],NULL,t_perfectos,(void *)i);
            }
            for (long i = 0; i < N_Esclavos; i++){
                pthread_join(t_esclavos[i],NULL);
            }
            for (long i = 0; i < N_Esclavos; i++){
                total_perfc += contPerfectos[i];    
            }
            printf("Numero perfectos encontrados: %d", total_perfc);
            
          
        }
    if(tid==1){
        printf("TiD-1: Mitrabajo es buscar numeros primos\n");
        printf("TiD-1: Numero de hijos lanzados: %d\n", N_Esclavos);
    }
    if(tid==2){
        printf("TiD-2: Mitrabajo es buscar numeros duros\n");
        printf("TiD-2: Numero de hijos lanzados: %d\n", N_Esclavos);
    }
    
   

    pthread_exit(NULL);
}

void * t_perfectos(void *arg){
    int tid_E = *((int *)(&arg));
    contPerfectos[tid_E]=0;
    int inicio = (tid_E * (iteraciones/N_Esclavos)) + 1;
    int final = (iteraciones/N_Esclavos) + (inicio + 1);
    int n_aux, suma;

    while (inicio <= final){
        n_aux = inicio-1;
        suma = 0;
        while (suma < inicio && n_aux > 0){
            if (inicio % n_aux == 0){
                suma += n_aux;
            }
            n_aux--;
        }
        if (suma == inicio){
            contPerfectos[tid_E] += 1;
        }
        inicio++;
    }
    
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