

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
void llenaMatriz();
void LFU_FIFO();
void imprimeAccesos(int , int *);
void reiniciaRAM();
void imprimeMatrizCompleta();
void FIFO();
bool buscaSecuencia(int**, int *, int);


//                                      VARIABLES GLOBALES

int **ram;
int *acceso;
int pgRAM;
int pgAcceso;
int vrand;
int sem;
time_t semilla;

/******************************************  FIN DE HEADER ****************************************************/



int main(int argc, char const *argv[]){
    presentacion();
    inicializaDatos();
    //LFU_FIFO();
    FIFO();
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
	scanf("%d",&sem);
    //casteo de la semilla
    semilla = (time_t)sem;
    llenaMatriz();   
    
}

void llenaMatriz(){
    //Arreglo que representa las secciones de paginas que seran accesadas
    acceso = (int *)malloc(pgAcceso*sizeof(int));

    // el numero 2 es el numero de filas (RAND y llegada o a si )
    ram =(int**)malloc(2*sizeof(int*));
    for (int i = 0; i <2; i++)
    {
        ram[i] = (int*)malloc(pgRAM*sizeof(int));
    }

    //Inicializamos la matriz igual a cero
    for (int i = 0; i <2; i++){
        printf("\n");
        for (int j = 0; j <pgRAM; j++)
        {
            ram[i][j]=0;
            //printf("%d ",ram[i][j]);
        }
        
    }
    // Ponemos la etiquetas de las secciones a accesar de manera aleatoria 
    srand((unsigned)time(&semilla));
	for(int i=0;i<pgAcceso;i++){
		acceso[i]=1+rand()%vrand;
        //printf("%d ",acceso[i] );
	}
}

void FIFO(){
    int contAccesos = pgAcceso;
    int *accesos = acceso;
    int contador=0;
    reiniciaRAM();
    system("clear");
    printf("\t /***************** First In First Out - FIFO*****************/ \n\n");
    //Se va a recorrer hasta acabar con toda la secuencia
    for (int i = 0; i < pgAcceso; i++){
        imprimeAccesos(contAccesos, accesos);
        if(buscaSecuencia(ram,accesos,i)==false){
            if(contador<pgRAM){
            ram[1][contador]=i+1;//etiqueta de llegada
            ram[0][contador]=acceso[i];//etiqueta de secuencia
            contador++;
            }
        }
        
        imprimeMatrizCompleta();  
        sleep(3);
        system("clear");
        
    }
    
    
}

// Recibe la ram, la secuencia y el indice que indica en que secuencia esta comparando 
bool buscaSecuencia(int**ram, int *acceso, int indice){
    for (int i = 0; i < pgRAM; i++)
    {
        if(ram[0][i]==acceso[indice]){
            return true;
        }
    }
    return false;
}

void LFU_FIFO(){
    int contAccesos = pgAcceso;
    int *accesos = acceso;
    reiniciaRAM();
    system("clear");
    printf("\t /***************** Least Frequently Used - LFU *****************/ \n\n");
    imprimeAccesos(contAccesos, accesos);
    
}

void imprimeMatrizCompleta(){
    for (int i = 0; i < 2; i++)
    {
        printf("\n");
        for (int j = 0; j < pgRAM; j++)
        {
            printf("%d ", ram[i][j]);
        }
        
    }
    
}

void imprimeAccesos(int contador, int *accesos){
    for (int i = 0; i < contador; i++)
    {
        printf(" %d", accesos[i]);
    }
}


void reiniciaRAM(){
    for (int i = 0; i <2; i++)
    {
        for (int j = 0; j <pgRAM; j++)
        {
            ram[i][j] =0;
        }
        
        
    }
}

