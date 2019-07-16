/***********************************************************************************************************************


                                        UNIVERSIDAD AUTONOMA METROPOLITANA
                                        NOMBRE: CARRILLO PACHECHO FRANCISCO JAVIER
                                        MATRICULA: 2143008102
                                        FECHA DE ENTREGA: 10/06/2019


 **********************************************************************************************************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

//EN ESTA PARTE HAGO LOS LLAMADOS DE LOS PROTOTIPOS QUE VOY A UTILIZAR PARA QUE C LOS PUEDA
//RECONOCER

void * t_control_total(void *arg);
void * t_perfectos(void *arg);
void * t_fuertes(void *arg);
void * t_primos(void *arg);
bool esPrimo(int num);
void strreversa(char* inicio, char* final);
void itoa_(int num, char *str);
int factorial(int numero);
int charToInt(char num);

#define N_Maestros 3
#define N_Esclavos  10000 //Modificamos el numero de hilos esclavos
int iteraciones;
int contPerfectos[N_Esclavos];
int contFuertes [N_Esclavos];
int contPrimos [N_Esclavos];
//int resultadoMaestros[N_Maestros];



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
    // Casteo para obtener el tid del hilo maestro
    int tid = *((int *)(&arg));   

    if(tid==0){
            printf("\nHola soy el maestro con el tid: %d\n",tid);
            printf("\nTiD-0: Mitrabajo es buscar numeros perfectos\n");
            printf("\nTiD-0: Numero de hijos lanzados: %d\n\n", N_Esclavos);
            pthread_t t_esclavos[N_Esclavos];//Hilos esclavos
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
        printf("\nNumero perfectos encontrados: %d", total_perfc);


        }
    if(tid==1){
        printf("\nHola soy el maestro con el tid: %d\n",tid);
        printf("\nTiD-1: Mitrabajo es buscar numeros primos\n");
        printf("\nTiD-1: Numero de hijos lanzados: %d\n\n", N_Esclavos);
        pthread_t t_esclavos[N_Esclavos];//Hilos esclavos
            int total_primos=0;
            for (long i = 0; i < N_Esclavos; i++){
                pthread_create(&t_esclavos[i],NULL,t_primos,(void *)i);
            }
            for (long i = 0; i < N_Esclavos; i++){
                pthread_join(t_esclavos[i],NULL);
            }
            for (long i = 0; i < N_Esclavos; i++){
                total_primos += contPrimos[i];
            }
        printf("\nNumeros primos encontrados: %d", total_primos);
    }
    if(tid==2){
        printf("\nHola soy el maestro con el tid: %d\n",tid);
        printf("\nTiD-2: Mitrabajo es buscar numeros fuertes\n");
        printf("\nTiD-2: Numero de hijos lanzados: %d\n\n", N_Esclavos);
        pthread_t t_esclavos[N_Esclavos];//Hilos esclavos
            int total_fuertes=0;
            for (long i = 0; i < N_Esclavos; i++){
                pthread_create(&t_esclavos[i],NULL,t_fuertes,(void *)i);
            }
            for (long i = 0; i < N_Esclavos; i++){
                pthread_join(t_esclavos[i],NULL);
            }
            for (long i = 0; i < N_Esclavos; i++){
                total_fuertes += contFuertes[i];
            }
        printf("\nNumeros fuertes encontrados: %d", total_fuertes);
    }



    pthread_exit(NULL);
}

void * t_perfectos(void *arg){
    int tid_E = *((int *)(&arg));
    contPerfectos[tid_E]=0;
    //Sacamos los intervalos a checar de cada hilo slave
    int inicio = (tid_E * (iteraciones/N_Esclavos)) + 1;
    int final = (iteraciones/N_Esclavos) + (inicio);
    int n_aux, suma;

    while (inicio < final){
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
    int tid_E = *((int *)(&arg));
    contPrimos[tid_E]=0;
    int inicio = (tid_E * (iteraciones/N_Esclavos));
    int final = (iteraciones/N_Esclavos) + (inicio);

    for (int i = inicio; i < final; i++){
       if (esPrimo(i)==true){
           contPrimos[tid_E] +=1;
       }

    }
    pthread_exit(NULL);
}

//Verifica si un numero es primo
bool esPrimo(int num){
    if (num<2){
        return false;
    }
    for (int i = 2; i <num; i++){
        if (num%i == 0){
            return false;
        }
    }
    return true;
}


void * t_fuertes(void *arg){
    int tid_E = *((int *)(&arg));
    contFuertes[tid_E]=0;
    int inicio = (tid_E * (iteraciones/N_Esclavos));
    int final = (iteraciones/N_Esclavos) + (inicio);
    char buf[BUFSIZ];

    int comprobar =0;
    for (int i = inicio; i < final; i++){
         itoa_(i,buf);//<--- El numero lo convierto a cadena de caracteres (divido digito a digito)
         for (int j = 0; j < strlen(buf); j++){
             comprobar = comprobar + factorial(charToInt((int)buf[j]));//<--- A cada digito le saco su factorial y cada resultado lo sumo y lo almaceno en comprobar
         }                                                             //utilizo el charToInt para ver que digito es, ya que lo converti anteriormente a caracteres
         if(comprobar ==i){
             contFuertes[tid_E] += 1;
             //printf("\n i: %d comprobar: %d\n",i,comprobar);
         }
         comprobar =0;
    }
    pthread_exit(NULL);
}

//metodo que me ayuda a enderezar el arreglo de caracteres
void strreversa(char* inicio, char* final)
{
    char aux;
    while(final>inicio)
        aux=*final, *final--=*inicio, *inicio++=aux;
}

//funcion que me ayuda a separar los digitos y convertilos a char
void itoa_(int num, char *str){
    char* wstr=str;
    int signo;
    //div_t res;

    if ((signo=num) < 0) num = -num;

    do {
      *wstr++ = (num%10)+'0';
    }while((num=(num/10)));

    if(signo<0) *wstr++='-';
    *wstr='\0';

    strreversa(str,wstr-1);//<---- Como el resultado me lo da al reves, esta funcion me ayuda a enderezarlo
}

//Saca el factorial
int factorial(int numero){
    if(numero<1){
        return 0;
    }
    else if(numero==1){
        return 1;
    }
    return numero * factorial(numero-1);
}


int charToInt(char num){
    if(num == 48){
        return 0;
    }
    if(num == 49){
        return 1;
    }
    if(num == 50){
        return 2;
    }
    if(num == 51){
        return 3;
    }
    if(num == 52){
        return 4;
    }
    if(num == 53){
        return 5;
    }
    if(num == 54){
        return 6;
    }
    if(num == 55){
        return 7;
    }
    if(num == 56){
        return 8;
    }
    return 9;


}
