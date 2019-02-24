#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <stdbool.h>

//EN ESTA PARTE HAGO LOS LLAMADOS DE LOS PROTOTIPOS QUE VOY A UTILIZAR PARA QUE C LOS PUEDA
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


int main(int argc, char const *argv[]){
    srand(time(NULL));
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
    float numeroB[40];
    char palo[40];  
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
   
    
}


void Juego(float numero[], char palos[]){
   
    int opc=0;
    do
    {
        int i = 0;
        float puntaje_u=0, puntaje_m=0;
        Inicializar_Baraja(numero,palos);
        Barajear(numero,palos);
        
        bool banderaJ;
        bool banderaM;
        banderaJ = Turno_Jugador(numero,palos,&puntaje_u,&i);
        
        if(banderaJ==true){
            printf("HAS PERDIDO LA PARTIDA, INSECTO, ¡¡VICTORIA PARA LA MAQUINA!!\n");
        }else{
            banderaM = Turno_Maquina(numero,palos,&puntaje_m,&i);
            //printf("%d",banderaM);
            if(banderaM==true){
                printf("HAS GANADO LA PARTIDA, REY DE LOS SAYAYIN\n");
            }
            else if(puntaje_m>=puntaje_u){
                printf("HAS PERDIDO LA PARTIDA, INSECTO, ¡¡VICTORIA PARA LA MAQUINA!!\n");
            }
            else{
                printf("HAS GANADO LA PARTIDA, REY DE LOS SAYAYIN\n");
            }
        }
        printf("¿Quieres jugar de nuevo?\n 1->[Si], 0->[No]\n");
        scanf("%d",&opc);
        if(opc==0){
            break;
        }
        system("clear");   

        
    } while (true);
    
    
}
void Simulacion(float numero[], char palos[]){
    float Puntoscpu1 =0, Puntoscpu2 =0;
    int NumGanadocpu1 =0, NumeroGanadocpu2 = 0;
    int NumSimulaciones =0;
    int recorre=0;
    printf("Cuantas simulaciones quieres realizar??\n");
	scanf("%d", &NumSimulaciones);
    for(int i = 0; i < NumSimulaciones; i++){
        Puntoscpu1 =0;
        Puntoscpu2 =0;
        recorre=0;
        Inicializar_Baraja(numero,palos);
        Barajear(numero,palos);
        for(int j = 0; j < 2; j++){   
            if(j==0){
                do
                {                
                    Puntoscpu1+=numero[recorre];
                    recorre++;
                    if(Puntoscpu1>7.5){
                        break;
                    }else if(Puntoscpu1>=6.5){
                        break;
                    }
                
                } while (1);

            }
            
           
            if(Puntoscpu1>7.5){
                //NumeroGanadocpu2++;
                break;
            }
            if(j==1){
                do
                {                
                    Puntoscpu2+=numero[recorre];
                    recorre++;
                    if(Puntoscpu2>6){
                        break;
                    }                
                } while (1);

            }
                
            
        }//fin segundo for
         //    printf("Ronda %d puntos cpu1 %.2f  pu2 %.2f\n",i,Puntoscpu1,Puntoscpu2);

        if(Puntoscpu1>7.5){
            NumeroGanadocpu2++;
        }
        else{
            if(Puntoscpu2>7.5){
                NumGanadocpu1++;
            }
            else{
                if(Puntoscpu2>=Puntoscpu1){
                        //printf("Mayor o igual");
                        NumeroGanadocpu2++;
                    }
                    else{
                        NumGanadocpu1++;
                    }

            }
            
        }
       

    }//Fin del primer for
     printf("Resultado de las %d simulaciones\n",NumSimulaciones);
	  printf("	Veces que ganó CPU1 con la opción de platarse en 6.5: %d\n", NumGanadocpu1);
	  printf("	Veces que ganó CPU2 con la opción de platarse en 6: %d\n\n", NumeroGanadocpu2);
	  printf("Presione una tecla para continuar...\n");
 	  char tec;
 	  scanf("%c", &tec);
  	 scanf("%c", &tec);
    
    

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
    //srand(time(NULL));//Te permite generar los numeros aleatorios mas chido
    int itera=rand()%979+20;
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
bool Turno_Jugador(float numero[], char palos[],float* puntaje_u, int* recorre){
     printf("\t\t\t\t TURNO DEL JUGADOR\n\n");

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
        *recorre+=1;
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
        
    } while (1);    

}
bool Turno_Maquina(float numero[], char palos[], float *puntaje_m, int *recorre){
    //printf("%d recorre" , *recorre);
    printf("\t\t\t\t TURNO DE LA MAQUINA\n\n");
    char paloAux[13];
    float numAux[13];
    int cantidad =0;
    do{
         printf("\t\t\t Ronda numero: %d \n", cantidad+1);
        paloAux[cantidad] = palos[*recorre];
        numAux[cantidad] = numero[*recorre];
        *puntaje_m +=numAux[cantidad];
        printf("\t\nLas cartas de la maquina son: \n\n");
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
        if(*puntaje_m>7.5){
            return true;
        }else if(*puntaje_m>6){
            return false;

        }    
        cantidad++;
        *recorre+=1;
    } while (1);    
    
}