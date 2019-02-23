#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <stdbool.h>
//EN ESTA PARTE HAGO LOS LLAMADOS DE LOS METODOS QUE VOY A UTILIZAR PARA QUE C LOS PUEDA
//RECONOCER
void Presentacion();
void Menu();
void ElegirOpcion(int *);
void Juego(float[], char[]);
void Inicializar_Baraja(float [], char []);
void Barajear(float [], char []);
void Simulacion (float [], char []);
bool Turno_Jugador(float [], char [],float *, int *);
bool Turno_Maquina(float [], char [],float *, int *);
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
void ElegirOpcion(int* opcionMenu){  
    if(*opcionMenu==1){
        system("clear");
        Juego(numeroB, palo);
    }else if(*opcionMenu==2){
        system("clear");
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
   
    int opc=0;
    do
    {
        int i = 0;
        float puntaje_u=0, puntaje_m=0;
        Inicializar_Baraja(numero,palos);
        Barajear(numero,palos);
        
        bool bandera;
        bandera = Turno_Jugador(numero,palos,&puntaje_u,&i);
        printf("¿Quieres jugar de nuevo?\n 1->[Si], 0->[No]\n");
        scanf("%d",&opc);
        if(opc==0){
            break;
        }
        system("clear");   

        
    } while (true);
    
    
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
    int itera=rand()%979+21;
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
        numero[c1] = numero[c2];       
        palos[c2] = Palaux;
        numero[c2] = Numaux;
    }
}
bool Turno_Jugador(float numero[], char palos[],float *puntaje_u, int *recorre){
    int opcion = 0;
    char paloAux[13];
    float numAux[13];
    int cantidad =0;
    
    
    do{
        printf("\t\t\t Ronda numero: %d \n", cantidad+1);
        paloAux[cantidad] = palos[*recorre];
        numAux[cantidad] = numero[*recorre];
        *puntaje_u += numAux[cantidad];
        printf("\t\nTus cartas hasta el momento son:\n\n");
        for(int i = 0; i < cantidad+1; i++){
            printf("\t%.2f de  ",numAux[i]);
            if(paloAux[i]=='O'){
                printf("Oros\n");                  
            }
            if(paloAux[i]=='C'){
                printf("Copas\n");
            } 
            if(paloAux[i]=='E'){
              printf("Espadas\n");
            } 
            if(paloAux[i]=='B'){
                printf("Bastos\n");

            }        
        }
        
        printf("\tTu puntaje es: %.2f\n\n", *puntaje_u);
        if(*puntaje_u>7.5){
            printf("Te has exedido de 7.5, tu puntaje es: %.2f\n",*puntaje_u);
            return true;
        }        
        printf("¿Quieres otra carta?\n 1->[Si], 0->[No]:  ");
        scanf("%d",&opcion);
        if(opcion==0){
            return false;
        }
        cantidad++;
        *recorre+=1;
    } while (1);    

}
bool Turno_Maquina(float numero[], char palos[], float *puntaje_m, int *recorre){
    char paloAux[13];
    char numAux[13];
    int cantidad =0;
    do{
        paloAux[cantidad] = palos[*recorre];
        numAux[cantidad] = numero[*recorre];
        *puntaje_m +=numAux[cantidad];
        printf("Las cartas de la mauina son:\n");
        for(int i = 0; i < cantidad+1; i++){
            printf("%.2f de",numAux[i]);
            switch(paloAux[i]){
                  case 'O': printf("Oros\n"); 
                  case 'C': printf("Copas\n");
                  case 'E': printf("Espadas\n"); 
                  case 'B': printf("Bastos\n");
            }            
        }
        if(*puntaje_m>7.5){
            return true;
        }else if(*puntaje_m>6.5){
            return false;

        }    
        cantidad++;
        *recorre+=1;
    } while (1);    
    
}