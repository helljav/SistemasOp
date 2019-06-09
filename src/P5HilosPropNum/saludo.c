#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strreverse(char* begin, char* end);
void itoa_(int value, char *str); 
int main(){
    char buf[BUFSIZ];
    int n = 2000;
    // sprintf(buf,"%d", n);
    // puts(buf);
    itoa_(n,buf);
    int tamano = strlen( buf);
    printf("%d",tamano);
    int entero = (int) buf[0];
    printf("imprimiendo a entero : %d", entero);

    
    return 0;
}

void strreverse(char* begin, char* end) 
{   
    char aux;   
    while(end>begin)    
        aux=*end, *end--=*begin, *begin++=aux;  
}
void itoa_(int value, char *str)
{
    char* wstr=str; 
    int sign;   
    //div_t res;
    
    if ((sign=value) < 0) value = -value;
    
    do {    
      *wstr++ = (value%10)+'0'; 
    }while((value=(value/10)));
    
    if(sign<0) *wstr++='-'; 
    *wstr='\0';

    strreverse(str,wstr-1);
}

