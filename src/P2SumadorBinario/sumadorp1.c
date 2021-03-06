#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include<string.h>

void Menu();
void ElegirOpcion(int*);
int comprobarDatos(char[]);
void ingresaDatos(char []);
void inicio(char [], char[]);
void charToInt(char [], int[]);
void sumador(int[], int[], int []);
int suma(int *, int , int);
void imprime(char [],char [], int []);


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
        //Variables que se utilizaran en el sumador
        int resultado[5]; // De 5 en caso de que el resultado sea de 5 caracteres
        char numero1[5];//Es de tamaño 5 ya que se toma en cuenta el: /0
        char numero2[5];
        int num1[4];
        int num2[4];

        inicio(numero1, numero2); //solicita las variables y las verifica       
        charToInt(numero1, num1); //Convierte de cadena de caracteres a entero
        charToInt(numero2, num2);       
        sumador(num1, num2, resultado);// Inica la suma
        imprime(numero1, numero2, resultado);//Imprime el resultado

    }else if(*opcionMenu==2){
        system("clear");
        printf("Adios");
        exit(0);
    }
   
    
}
void sumador(int num1[], int num2[], int resultado[]){   
    resultado[0] = 0;    
    // num guarda el resultado de sumar dígito a dígito
    int num,ac = 0;    
    int N  = 5;

    for(int i = N; i > 0; i--){ // El recorrido de los arreglos se hace al revés por regla
	        // Se hace la suma y se guarda el resultado
	        num = suma(&ac, num1[i-1], num2[i-1]);
            //suma(ac,num1,num2);
	        resultado[i] = num;
            //printf("%d",num);

        }
    if(ac==1){
        resultado[0]=1;
    }
}

void imprime(char num1[],char num2[], int resultado[] ){
    printf("   %s  ", num1);
    printf("\n+");
    printf("\n   %s  ", num2);
    printf("\n__________\n  ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", resultado[i]);
    }
    char tec;
    scanf("%c",&tec);
    printf("\t\tPresione cualquier tecla para continuar...\n");
    scanf("%c",&tec);

}
int suma(int *ac, int a, int b){
	if(*ac == 0){ // EL ACARREO ES 0
		if((a + b) == 1){ //Casos: a = 0 y b = 1; a = 1 y b = 0
			*ac = 0;
			return 1;
		}
		if((a + b) == 2){ // Caso: a = b = 1
			*ac = 1;
			return 0;
		}
		*ac = 0; //Caso a = b = 0;
		return 0;
	}
	else{ // EL ACARREO ES 1
		if((a + b) == 1){ //Casos: a = 0 y b = 1; a = 1 y b = 0
			*ac = 1;
			return 0;
		}
		if((a + b) == 2){ // Caso: a = b = 1
			*ac = 1;
			return 1;
		}
		*ac = 0; //Caso a = b = 0;
		return 1;
	}
    
}

void charToInt(char num[], int numero[]){
    
    for (int i = 0; i <4; i++){
            int aski = (int)num[i];//Te devuelve el codigo ascii
            if(aski == 49){
                numero[i] = 1;
            }
            else{
                numero[i] = 0;
            }
            //printf("\n%d", numero[i]);
        }
}
void inicio(char numero1[], char numero2[]){
        printf ("\nIngrese el primer numero--> ");
        scanf("%s", numero1);
        ingresaDatos(numero1);
        printf ("\nIngrese el segundo numero--> ");
        scanf("%s", numero2);
        ingresaDatos(numero2);

}

void ingresaDatos(char numero[]){
    int bool = comprobarDatos(numero);
        if(bool ==1){
            do{
                system("clear");
                printf("Numero incorrecto:\n");
                printf("Ingrese un numero correcto de 4 bits\n");
                scanf("%s", numero);
                system("clear");
                bool = comprobarDatos(numero);

            }while(bool==1);
        }
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
    system("clear");
    printf("Bienvenido al sumador binario de 4 bits\n");
    printf("1. Realizar una suma\n");
    printf("2. Salir del programa\n");
    printf("Elige una de las opciones anteriores\n\n");

}