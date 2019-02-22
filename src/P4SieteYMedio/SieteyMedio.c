#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
//EN ESTA PARTE HAGO LOS LLAMADOS DE LOS METODOS QUE VOY A UTILIZAR PARA QUE C LOS PUEDA
//RECONOCER
void Presentacion();
void Menu();
void ElegirOpcion(int *);
void Juego(float[], char[]);
void Inicializar_Baraja(float [], char []);
void Barajear(float [], char []);
void Simulacion (float [], char []);
void Turno_Jugador(float [], char [],float *, int *);
void Turno_Maquina(float [], char [],float *, int *);
//Crei conveniente hacer los arreglos globales
float numeroB[40];
char palo[40];

int main(int argc, char const *argv[]){
    Presentacion();
    int opcionMenu =0;
    do{
        Menu();
        scanf("%d",&opcionMenu);
        ElegirOpcion(&opcionMenu);
        system("clear");        
    }while(opcionMenu!=3);    
}
//Relizando los metodos

void Presentacion(){
    system("clear");
    printf("\n");

    printf("\n\t\t\t**   **      ****      **        **");
    printf("\n\t\t\t**   **    **    **    ***      ***");
    printf("\n\t\t\t**   **    ********    **   **   **");
    printf("\n\t\t\t*******    **    **    **        **");
    printf("\n\t\t\t ****      **    **    **        **");	
	printf("\n\n\tSIMULACION DEL JUEGO SIETE Y MEDIO\n");
    printf("\tAUTOR: CARRILLO PACHECO FRANCISCO JAVIER\t\t2143008102\n");
	printf("\tFECHA DE CREACION: 25/FEBRERO/2019\n\n");
	printf("\t\tPresione cualquier tecla para jugar...\n");
	char tec;
	scanf("%c",&tec);

}

void Menu(){
    printf("Bienvenido al Menu, ¿Que deseas hacer? :\n");
    printf("\t1.- Jugar contra la máquina (jugador VS CPU)\n");
    printf("\t2.- Realizar una simulacion entre CPU vs CPU\n");
    printf("\t3.- Salir\n");
    printf("Elige una de las anteriores opciones ");

}
void ElegirOpcion(int *opcionMenu){  
    if(*opcionMenu==1){
        Juego(numeroB, palo);

    }else if(*opcionMenu==2){
        Simulacion(numeroB,palo);
    }else if(*opcionMenu==3){
        printf("Adios");
        exit(0);
    }
    //  for(int i = 0; i < 40; i++)
    // {
    //     printf("%c",palo[i]);
    // }
    
}


void Juego(float numero[], char palos[]){
    Inicializar_Baraja(numero,palos);
    Barajear(numero,palos);   

}
void Simulacion(float numero[], char palos[]){
    Inicializar_Baraja(numero,palos);
    Barajear(numero,palos);

}

void Inicializar_Baraja(float numero[], char palos[]){
    int contpalo =0;
    for(int i=0; i<4; i++){
        for(int j = 0; j<10; j++)
        {
            //llenado de los palos
            if(i==0){
                palos[contpalo] = 'O';
                contpalo++;
            }
            if(i==1){
                palos[contpalo] = 'C';
                contpalo++;
            }
            if(i==2){
                palos[contpalo] = 'E';
                contpalo++;
            }
            if(i==3){
                palos[contpalo] = 'B';
                contpalo++;
            }
            //Llenado del valor del numero de las cartas
            if(j>6){
    		  numero[i*10+j]=0.5;
    		}else{
              numero[i*10+j]=j+1;
    		}
        }        
    }

}

void Barajear(float numero[], char palos[]){
    int itera=rand()%979+21;//Aleatorios entre 20 y 1000
    int c1=0;
	int c2=0;
	float Numaux=0;
    char Palaux;
    for(int i=0; i<itera;i++){
        c1=rand()%40;
    	c2=rand()%40;
        Palaux = palos[c1];
        Numaux = numero[c1];
        palos[c1] = palos[c2];
        numero[c1] = palos[c2];
        palos[c2] = Palaux;
        numero[c2] = Numaux;
    }
}
void Turno_Jugador(float numero[], char palos[],float *puntaje, int *recorre){
    char paloAux[13];
    char numAux[13];

}
// void Turno_Maquina(float [], char [], float *, int *){
    
// }