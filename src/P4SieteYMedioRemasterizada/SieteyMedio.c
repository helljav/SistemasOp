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
bool Turno_Jugador(float [], char [],float *, int *,float [], float *,int *);
bool Turno_Maquina(float [], char [],float *, int *, float [], float *, int * , float [], float [2][8], int *);
void calcProb(float *, float [], int *, float [], int *, float [2][8]);
void cartaX(float *, float, int *, float []);
void reinicia(float cartas_acom[], float prob_ap[], float mprob[2][8]);
bool iaMaquina(float cartas_acom[], float *puntaje_m, float prob_ap[], float mprob[2][8], int *total_c);
//Crei conveniente hacer los arreglos globales


int main(int argc, char const *argv[]){
    srand(time(NULL));//Reinicia la variable para recalar la variable aleatoria para la baraja
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

    printf("\n\t\t\t     **   **      ****      **        **");
    printf("\n\t\t\t     **   **    **    **    ***      ***");
    printf("\n\t\t\t     **   **    ********    **   **   **");
    printf("\n\t\t\t     *******    **    **    **        **");
    printf("\n\t\t\t      ****      **    **    **        **");	
    printf("\n\n\n\t     SIMULACION DEL JUEGO SIETE Y MEDIO\n");
    printf("\n\t     AUTOR: °CARRILLO PACHECO FRANCISCO JAVIER\t\t2143008102\n");
    printf("\t\t    °RAYA CHULA RICARDO\t\t0\n");
    printf("\t     FECHA DE CREACION V1.0.0.5: 02/JUNIO/2019\n\n");
    printf("\t\t     Presione ENTER para jugar...\n");
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
        // Declarar mas variables para poder hacer la probabilidad
        float cartas_acom[40]; //cartas que tiene el jugador en su mano
        float suma=0; //Suama del arreglo de cartas_acom
        int i = 0;//variable recorre (recorre la baraja)
        float puntaje_u=0, puntaje_m=0;//Puntaje de jugador y puntaje de la maquina
        int total_c=40;//Resto de las cartas que quedan en la baraja
        float prob_ap[8];
        float mprob[2][8];
        int contx=0;
        reinicia(cartas_acom, prob_ap,  mprob);
        Inicializar_Baraja(numero,palos);
        Barajear(numero,palos);
        //Estas variables tendran el puntaje de cada jugador
        bool banderaJ;
        bool banderaM;

        banderaJ = Turno_Jugador(numero,palos,&puntaje_u,&i,cartas_acom,&suma,&total_c);
        
        if(banderaJ==true){
            printf("HAS PERDIDO LA PARTIDA, INSECTO, ¡¡VICTORIA PARA LA MAQUINA!!\n");
        }else{
            banderaM = Turno_Maquina(numero,palos,&puntaje_m,&i,cartas_acom,&suma,&total_c,prob_ap,mprob,&contx);
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
void reinicia(float cartas_acom[], float prob_ap[], float mprob[2][8]){
       for (int i = 0; i <40; i++)
       {
           cartas_acom[i]=0;
       }
       for (int i = 0; i <8; i++)
       {
           prob_ap[i]=0;
       }
       for (int i = 0; i <2; i++)
       {
           for (int j = 0; j < 8; j++)
           {
                mprob[i][j] = 0;
           }          
           
       }      
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
       //Intercambiando cartas
        palos[c1] = palos[c2];
        numero[c1] = numero[c2];       
        palos[c2] = Palaux;
        numero[c2] = Numaux;
    }
}

void calcProb(float *suma, float cartas_acom[], int *total_c, float prob_ap[], int *contx, float mprob[2][8]){
    *contx =0;
    float frecuencia =0.0;
    float suma_prob = 0.0;
    
    //posibles candidatos de la carta X
    cartaX(suma,0.5,contx,prob_ap);
    cartaX(suma,1.0,contx,prob_ap);
    cartaX(suma,2.0,contx,prob_ap);
    cartaX(suma,3.0,contx,prob_ap);
    cartaX(suma,4.0,contx,prob_ap);
    cartaX(suma,5.0,contx,prob_ap);
    cartaX(suma,6.0,contx,prob_ap);
    cartaX(suma,7.0,contx,prob_ap);
    
    //printf("\nconteo total_c %d", *total_c);

    //Se sacamos la frecuencia de las cartas acomuladas y la asignamos en la matriz
    for (int i = 0; i <*contx; i++){
        for (int j = 0; j < sizeof(*cartas_acom); j++){
            if(prob_ap[i]==cartas_acom[j]){
                frecuencia ++;                
            }            
        }
        mprob[1][i] = prob_ap[i];
        
        mprob[0][i] = frecuencia;        
        frecuencia = 0.0;                     
    }
    //sacando las P(Bi)
    for (int i = 0; i <8; i++){
       if(mprob[0][i]>0){
           if(i==0){
            mprob[0][i] = ((12-mprob[0][i])/ (*total_c + 1.0));
           }
           else{
            mprob[0][i] = ((4-mprob[0][i])/ (*total_c + 1.0));
           }
       }
       else if(mprob[1][i]>0){
           float figura = 12.0/ (*total_c + 1.0);
           float otra = 4.0 / (*total_c + 1.0);           
           if(i==0){
            mprob[0][i] = figura;
           }
           else{
            mprob[0][i] = otra;
           }
           
       }
       else{
           mprob[0][i] = 0;
       }      
        suma_prob = suma_prob + mprob [0][i]; //(P(A))            
   }
   //Aqui ya calculamos bayes
   for (int i = 0; i < 8; i++)
   {
        if(suma_prob!=0){
            mprob [0][i] = mprob [0][i] / suma_prob;
        }
   }
    
}

void cartaX(float *suma, float carta, int *contx, float porb_ap[]){
    //La variable carta, representa el valor de la posible carta X
    //Si la suma de los valores de las cartas visibles, mas la posible carta X es menor que 7.5
    // El valor de "Carta", es una candidata a la carta X, entonces la guardamos en el arreglo
   float objetivo = (*suma +carta);
    if(objetivo <= 7.5){
        porb_ap[*contx]=carta;
        *contx += 1;
         
    }
   

}

bool Turno_Jugador(float numero[], char palos[],float* puntaje_u, int* recorre, float cartas_acom[], float *suma, int * total_c){
     printf("\t\t\t\t TURNO DEL JUGADOR\n\n");

    int opcion = 0;
    char paloAux[13];//palos que se le dara al jugador
    float numAux[13];//numero de carta que se le dara al jugador
    int cantidad =0;//indice que recorre a los arreglos auxiliares  
    
    do{
        printf("\t\t\t Ronda numero: %d \n", cantidad+1);
        paloAux[cantidad] = palos[*recorre];
        numAux[cantidad] = numero[*recorre];
        cartas_acom[cantidad] = numero[*recorre];
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
        //Modificamos nuestros indices y apuntadores
        
        *recorre+=1;//Seria nuestra i
        cantidad++;
        *total_c-=1;//cantidad de cartas que aun hay en la baraja 

        printf("\tTu puntaje es: %.2f\n\n", *puntaje_u);
        if(*puntaje_u>7.5){
            printf("Te has exedido de 7.5, tu puntaje es: %.2f\n",*puntaje_u);
            return true;
        }        
        printf("¿Quieres otra carta?\n 1->[Si], 0->[No]:  ");
        scanf("%d",&opcion);
        if(opcion==0){
            cartas_acom[*recorre-1]=0;
            
            //printf("\nturno maquina recorriendo cartas_acom\n");
            for (int j = 0; j < *recorre; j++)
            {
                *suma += cartas_acom[j];
               printf("\ncarta acomulada: %f", cartas_acom[j]);
            }           
            
            return false;
        }
               
    } while (1);
}

bool Turno_Maquina(float numero[], char palos[], float *puntaje_m, int *recorre, float cartas_acom[], float *suma, int * total_c, float prob_ap[], float mprob[2][8], int *contx){
    //printf("%d recorre" , *recorre);
    printf("\t\t\t\t TURNO DE LA MAQUINA\n\n");
    char paloAux[13];
    float numAux[13];
    int cantidad =0;
    
    
    do{
         printf("\t\t\t Ronda numero: %d \n", cantidad+1);
        paloAux[cantidad] = palos[*recorre];
        numAux[cantidad] = numero[*recorre];
        cartas_acom[cantidad] = numero[*recorre];
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
        cantidad++;
        *recorre+=1;
        *total_c -=1;    
        calcProb(suma, cartas_acom,total_c,prob_ap, contx, mprob);
        bool valorObjetivo = iaMaquina(cartas_acom,puntaje_m, prob_ap,mprob, total_c);
        if(*puntaje_m>7.5){
            return true;
        }else if(valorObjetivo==true){//si se alcanza un valor objetivo deja de pedir
            return false;

        }    
        
    } while (1);    
    
}



bool iaMaquina(float cartas_acom[], float *puntaje_m, float prob_ap[], float mprob[2][8], int *total_c){
    float pg=0.0;
    float pp=0;
    float difpuntos[8];
    // puntaje_m va a se nuestro pg
    //mprob[0][i] (P(Bi|A)) va a ser nuestro pp

    // Determinamos el valor de pg
    for (int i = 0; i <8; i++){
        if(i==0){
            if(*puntaje_m >= (mprob[1][i] + 0.5)){
                 pg =  mprob[0][i];
                 break;
            }    
        }
        else{
             if(*puntaje_m >= (mprob[1][i] + i)){
                pg = mprob[0][i];
                break;
            }
        }
      
                       
    }
    printf("\n\n soy pg: %f\n", pg);

    //Determinamos el valor de pp
    //Posibibles cartas donde te pasarias del 7.5 si pides una mas
    for (int i = 0; i < 8; i++)
    {
        if(i==0.0){
            if((*puntaje_m + 0.5)>7.5){
                difpuntos[i] = (float)i;
            }
            else
            {
                difpuntos[i] = 0.0;
            }
            
        }
        else
        {
            if((*puntaje_m + (float)i)>7.5){
                difpuntos[i] = (float)i;
            }
            else
            {
                difpuntos[i] = 0.0;
            }   
        }
        difpuntos[i] = difpuntos[i] / (*total_c + 1.0);
        pp = pp + difpuntos[i];
       // printf("\n soy difpuntos[i]: %f", difpuntos[i]);
    }

    printf("\nsoy pp %f\n", pp);
    if(pg>=0.7||pg>=0.01){
        if(pp>0.5){
            return true;
        }
        else
        {
            return false;
        }
        
    }
    return false;  
    
    

}