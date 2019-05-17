#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include<string.h>

void Menu();
void ElegirOpcion(int*);
int comprobarDatos(char[]);
void suma();
void ingresaDatos();
char numero1[3];
char numero2[3];

int main(int argc, char const *argv[]){
    int opcionMenu =0;
    do{
        Menu();
        scanf("%d",&opcionMenu);
        ElegirOpcion(&opcionMenu);
               
    }while(opcionMenu!=2);
}

void ElegirOpcion(int* opcionMenu){  
    if(*opcionMenu==1){
        // printf ("\nIngrese el primer numero--> ");
        // ingresaDatos(numero1);
        // printf ("\nIngrese el segundo numero--> ");
        // ingresaDatos(numero2);

        // printf("%s", numero2);
        // printf("%s", numero1);
        // printf("\n Conviertiendo a entero");
        // for (int i = 0; i <sizeof(numero1); i++)
        // {
        //     int num = atoi(numero1);
        //     printf("\n%d", num);
        // }
        
        ingresaDatos();
        printf("%s", numero2);
        printf("%s", numero1);
        suma();

    }else if(*opcionMenu==2){
        system("clear");
        printf("Adios");
        exit(0);
    }
   
    
}

void ingresaDatos(){
    printf ("\nIngrese el primer numero--> ");
    scanf("%s",numero1);
    int bool = comprobarDatos(numero1);
        if(bool ==1){
            do{
                printf("Numero incorrecto:\n");
                printf("Ingrese un numero correcto de 4 bits\n");
                scanf("%s", numero1);
                system("clear");
                bool = comprobarDatos(numero1);

            }while(bool==1);
    }


    printf ("\nIngrese el segundo numero--> ");
    scanf("%s",numero2);
    bool = comprobarDatos(numero2);
        if(bool ==1){
            do{
                printf("Numero incorrecto:\n");
                printf("Ingrese un numero correcto de 4 bits\n");
                scanf("%s", numero2);
                system("clear");
                bool = comprobarDatos(numero2);

            }while(bool==1);
    }
        
    
    }

void suma(){
    printf("i am here");
    
}

int comprobarDatos(char numero[]){
    int tamanio = 0;
    tamanio = strlen(numero);
    if(tamanio > 4 || tamanio < 4){
        return 1;            
    }else{
        for(int  i = 0; i < 4; i++){
        
        if(numero[i] != '1' && numero[i] != '0'){
            return 1;
        }       
    }
        
    }
    return 0;

}

void Menu(){
    printf("Bienvenido al sumador binario de 4 bits\n");
    printf("1. Realizar una suma\n");
    printf("2. Salir del programa\n");
    printf("Elige una de las opciones anteriores\n\n");

}