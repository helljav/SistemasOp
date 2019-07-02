

//                                              HEADER
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

//                              DECLACARACION DE PROTOTIPOS
void presentacion();
void inicializaDatos();



//                                      VARIABLES GLOBALES

int **ram;
int *acceso;
int pgRAM;
int pgAcceso;
int vrand;
int semilla;

int main(int argc, char const *argv[]){
    presentacion();
    inicializaDatos();
}

void presentacion(){
    system("clear");
    printf("\n\n\n");
    printf("\n\t\t\tSistemas Operativos");
    printf("\n\n\t\t\t\tPractica 7\n");	
	printf("\n\n\t\tMetodos de remplazo de paginas\n");
    printf("\n\t* Menos frecuentemente accesada + FIFO - LFU");
    printf("\n\t* Menos frecuentemente usada- LRU");
    printf("\n\t* Primero en entrar, primero en salir- FIFO");
    printf("\n\n\nPrograma hecho por: ");
    printf("\n\n -CARRILLO PACHECO FRANCISCO JAVIER\t\t2143008102\n");
	printf("\nFECHA DE CREACION: 15/JULIO/2019\n\n");
	printf("\n\t\tPresione cualquier tecla para continuar...\n");
	char tec;
	scanf("%c",&tec);

}
void inicializaDatos(){
    system("clear");
    printf("Dame el número de páginas en RAM\n\n");      /* CAPTURA DE DATOS INGRESADOS POR EL USUARIO */
	scanf("%d",&pgRAM);
	printf("Ingresa el número total de páginas que serán accesadas\n\n");
	scanf("%d",&pgAcceso);
	printf("Ingresa el rango del de RAND (limite del numero de etiquetas)\n\n");
	scanf("%d",&vrand);
	printf("Ingresa la semilla para iniciar el rand()\n");
	scanf("%d",&semilla);
    acceso = (int *)malloc(pgAcceso*sizeof(int));
    // el numero 2 es el numero de filas (RAND y llegada o a si )
    ram =(int**)malloc(2*sizeof(Info*));
    for (int i = 0; i <2; i++)
    {
        ram[i] = (int*)malloc(pgAcceso*sizeof(int));
    }
    
    
    
}

