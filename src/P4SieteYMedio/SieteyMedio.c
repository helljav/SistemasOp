#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
//EN ESTA PARTE HAGO LOS LLAMADOS DE LOS METODOS QUE VOY A UTILIZAR PARA QUE C LOS PUEDA
//RECONOCER
void Presentacion();
void Menu();
void ElegirOpcion(int *);
void Juego(float[], char[]);

int main(int argc, char const *argv[]){
    Presentacion();
    int opcionMenu =0;
    do{
        Menu();
        scanf("%d",&opcionMenu);
        ElegirOpcion(&opcionMenu);//Se pasa el apuntador para que se pueda modificar 
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
	printf("\tFECHA DE CREACION: 25 FEBRERO 2019\n\n");
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


}


void Juego(float numero[], char palos[]){

}
void Simulacion(float numero[], char palos[]){

}
