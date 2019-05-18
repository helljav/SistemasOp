#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include<string.h>

void pruebita(char []);


int main(int argc, char const *argv[]){
    char hola[3];
    char hola2[3];
    pruebita(hola);
    pruebita(hola2);
    printf("ummmm%s",hola);
    printf("\n%s",hola2);
    
}
void pruebita(char hola[]){
    scanf(" %s", hola);
    fflush(stdin);
} 