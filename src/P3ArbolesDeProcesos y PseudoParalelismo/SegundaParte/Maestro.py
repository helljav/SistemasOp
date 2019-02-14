# -*- coding: utf-8 -*-
# C:/Users/HP/Desktop/'Sistemas operativos'/src/'P3ArbolesDeProcesos y PseudoParalelismo'/SegundaParte

import os
import sys
import time
import getpass
import random
class maestro(object):
    #constructor
    def __init__( self, cantidad ):
        self.aleatorios =0
        self.cantidad = cantidad
        self.creaArreglo(self.cantidad)
        self.iniciaApp()

    def creaArreglo(self, cantidad):        
        aleatorios = [random.randint(1,10000) for _ in range(cantidad)]
        print(aleatorios)

    def iniciaApp(self):
        pid = os.fork()
        if(pid==0):
            os.execlp("python3","python3","buscaPares.py",str(self.aleatorios),str(self.cantidad))
            sys.exit(0)
        hijo=os.wait()

            
       

##
# Metodo Main
##
def main():
    print("")
    print ("\tBusqueda de numeros pares, impares, primos y perfectos")
    print ("\nSoy el padre de todos los procesos mi PID es: ",os.getpid())    

    while(True):
        try:
            n = int(input("Proporciona el numero de elementos en el arreglo: "))
            break           
        except:
            print("Ingrese un numero entero valido")
    print(os.getpid(),": Iniciando la lista de ",n,"elementos")
    inicia = maestro(n)
    

main()
        
   
    
    
        

   

    



   
