

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
int buscaComoFIFO(int **);
void LRU();


//                                      VARIABLES GLOBALES

int **ram;
int *acceso;
int *frecuencia;
int pgRAM;
int pgAcceso;
int vrand;
int sem;
time_t semilla;
int indiceSecuencia=0;
#define PGRAM_MAX 50
#define PGACCESO_MAX 200


/******************************************  FIN DE HEADER ****************************************************/



int main(int argc, char const *argv[]){
    presentacion();
    inicializaDatos();
    //FIFO();
    //sleep(3);
    LRU();
    //LFU_FIFO();
}

void presentacion(){
    system("clear");
    printf("\n\n\n");
    printf("\n\t\t\t      Sistemas Operativos");
    printf("\n\n\t\t\t\t  Practica 7\n");
	printf("\n\n\t\t\tMetodos de remplazo de paginas\n");
    printf("\n\t\t* Menos frecuentemente accesada + FIFO - LFU");
    printf("\n\t\t* Menos frecuentemente usada- LRU");
    printf("\n\t\t* Primero en entrar, primero en salir- FIFO");
    printf("\n\n\nPrograma hecho por: ");
    printf("\n\nCARRILLO PACHECO FRANCISCO JAVIER\t\t2143008102\n");
	printf("\nFECHA DE CREACION: 15/JULIO/2019\n\n");
	printf("\n\t\tPresione ENTER para continuar...\n");
	char tec;
	scanf("%c",&tec);

}
void inicializaDatos(){
    system("clear");
    printf("Dame el número de páginas en RAM\n\n");      /* CAPTURA DE DATOS INGRESADOS POR EL USUARIO */
	scanf("%d",&pgRAM);
     if(pgRAM>PGRAM_MAX){
        printf("Son muchas paginas en RAM, se asignara auntomaticamente 50\n");
        pgRAM=PGRAM_MAX;
    }
	printf("Ingresa el número total de páginas que serán accesadas\n\n");
	scanf("%d",&pgAcceso);
    if(pgAcceso>PGACCESO_MAX){
        printf("Son muchas paginas para ser accesadas, se asignara automaticamnete");
        pgAcceso=PGACCESO_MAX;
    }
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
    frecuencia = (int *)malloc(pgRAM*sizeof(int));

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
// Inicializamos la frecuencia
  for(int i=0;i<pgRAM;i++){
		frecuencia[i]=0;
	}
}

void FIFO(){
    //int contAccesos = pgAcceso;
    int *accesos = acceso;
    int contador=0;
    int pgFault=-1;
    reiniciaRAM();

    //Se va a recorrer hasta acabar con toda la secuencia
    for (int i = 0; i < pgAcceso+1; i++){
        system("clear");
        printf("\n\t /********************* First In First Out - FIFO ******************/ \n\n");
        imprimeAccesos(i, accesos);
        imprimeMatrizCompleta();
        printf("\n");
        if(buscaSecuencia(ram,accesos,i)==false){
            if(contador<pgRAM){//La memoria ram aun no se encuentra llena
                ram[1][contador]=contador+1;//etiqueta de llegada
                ram[0][contador]=acceso[i];//etiqueta de secuencia
                contador++;
                pgFault++;
            }
            else{
                // Si la pila ya esta llena, tenemos que sacar como FIFO tener que  meter como FIFO
                int indice = buscaComoFIFO(ram);//se obtiene el indice de donde tenemos que hacer el intercambio
                ram[1][indice]=contador+1;//etiqueta de llegada
                ram[0][indice]=acceso[i];//etiqueta de secuencia
                contador++;
                pgFault++;

            }
        }
        sleep(3);
    }
    printf("Numero de Page Fault: %d", pgFault);

}

void LRU(){
    printf("\n");
    sleep(5);
    system("clear");
    //int contAccesos = pgAcceso;
    int *accesos = acceso;
    int contador=0;
    int contadorLlegada=0;
    int pgFault=-1;
    int actualizaciones=0;
    reiniciaRAM();

    //Se va a recorrer hasta acabar con toda la secuencia de paginas a accesar
    for (int i = 0; i < pgAcceso+1; i++){
        system("clear");
        printf("\n\t /********************* Least Recently Used - LRU ******************/ \n\n");
        imprimeAccesos(i, accesos);
        imprimeMatrizCompleta();
        printf("\n");
        if(buscaSecuencia(ram,accesos,i)==false){//Si la pagina en la secuencia no se encuentra en la RAM, entra
            if(contador<pgRAM){//SI la memoria RAM aun no se encuentra llena
                ram[1][contador]=contadorLlegada+1;//etiqueta de llegada
                ram[0][contador]=acceso[i];//etiqueta de secuencia
                contador++;
                contadorLlegada++;
                pgFault++;
              }
            else{
                // Si la pila ya esta llena, tenemos que sacar como FIFO tener que  meter como FIFO
                int indice = buscaComoFIFO(ram);//se obtiene el indice de donde tenemos que hacer el intercambio
                ram[1][indice]=contadorLlegada+1;//etiqueta de llegada
                ram[0][indice]=acceso[i];//etiqueta de secuencia
                contador++;
                contadorLlegada++;
                pgFault++;

            }
        }
        else{//Si esa pagina ya se encuentra en la RAM, Solo se actualiza el tiempo de llegada
          ram[1][indiceSecuencia]=contadorLlegada+1;//etiqueta de llegada
          contadorLlegada++;
          actualizaciones++;//Contador para checar cuantas actualizaciones se hicieron
        }
        sleep(3);
    }
    printf("Numero de Page Fault: %d", pgFault);
    printf("\nNumero de actualizaciones hechas: %d",actualizaciones );

}


//Checa las llegadas de cada secuencia y la que lleva mas tiempo (la llegada mas corta) a esa se le hara el intercambio en FIFO
int buscaComoFIFO(int **ram){
    int aux=10000;
    int indice=0;
    for (int i = 0; i < pgRAM; i++){
        if(ram[1][i]<aux){
            aux=ram[1][i];
            indice=i;
        }
    }
    return indice;
}

// Verifica si una secuencia ya se encuentra en la memorua RAM
// Recibe la ram, la secuencia y el indice que indica en que secuencia esta comparando
bool buscaSecuencia(int**ram, int *acceso, int indice){
    for (int i = 0; i < pgRAM+1; i++)
    {
        if(ram[0][i]==acceso[indice]){
            indiceSecuencia = i;
            return true;

        }
    }
    return false;
}

void LFU_FIFO(){
  printf("\n");
  sleep(5);
  system("clear");
  //int contAccesos = pgAcceso;
  int *accesos = acceso;
  int contador=0;
  int contadorLlegada=0;
  int pgFault=-1;
  int actualizaciones=0;
  reiniciaRAM();

  //Se va a recorrer hasta acabar con toda la secuencia de paginas a accesar
  for (int i = 0; i < pgAcceso+1; i++){
      system("clear");
      printf("\n\t /********************* Least Frequently Used - LFU ******************/ \n\n");
      imprimeAccesos(i, accesos);
      imprimeMatrizCompleta();
      printf("\n");
      if(buscaSecuencia(ram,accesos,i)==false){//Si la pagina en la secuencia no se encuentra en la RAM, entra
          if(contador<pgRAM){//SI la memoria RAM aun no se encuentra llena
              ram[1][contador]=contadorLlegada+1;//etiqueta de llegada
              ram[0][contador]=acceso[i];//etiqueta de secuencia
              contador++;
              contadorLlegada++;
              pgFault++;
            }
          else{
              // Si la pila ya esta llena, tenemos que sacar como FIFO tener que  meter como FIFO
              int indice = buscaComoFIFO(ram);//se obtiene el indice de donde tenemos que hacer el intercambio
              ram[1][indice]=contadorLlegada+1;//etiqueta de llegada
              ram[0][indice]=acceso[i];//etiqueta de secuencia
              contador++;
              contadorLlegada++;
              pgFault++;

          }
      }
      else{//Si esa pagina ya se encuentra en la RAM, Solo se actualiza el tiempo de llegada
        ram[1][indiceSecuencia]=contadorLlegada+1;//etiqueta de llegada
        contadorLlegada++;
        actualizaciones++;//Contador para checar cuantas actualizaciones se hicieron
      }
      sleep(3);
  }
  printf("Numero de Page Fault: %d", pgFault);
  printf("\nNumero de actualizaciones hechas: %d",actualizaciones );


}

void imprimeMatrizCompleta(){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < pgRAM; j++)
        {
            printf("[%d]", ram[i][j]);
        }
        printf("\n");

    }

}

void imprimeAccesos(int indice, int *accesos){
    printf("\nLas paginas a acceder son: \n");
    for (int i = indice; i < pgAcceso; i++)
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
