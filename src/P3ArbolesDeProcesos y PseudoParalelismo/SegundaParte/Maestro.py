# -*- coding: utf-8 -*-
# C:/Users/HP/Desktop/'Sistemas operativos'/src/'P3ArbolesDeProcesos y PseudoParalelismo'/SegundaParte

import os
import sys
import time
import getpass
import random
from time import time
class maestro(object):
    #constructor
    def __init__( self, cantidad ):
        self.aleatorios = []
        self.cantidad = cantidad
        self.creaArreglo(self.cantidad)
        self.iniciaApp()

    def creaArreglo(self, cantidad):        
        self.aleatorios = [random.randint(1,10000) for _ in range(cantidad)]
        

    def iniciaApp(self):
        pid1 = os.fork()
        if(pid1==0):
            print ("\t",os.getpid(),": Metodo para encontrar los numeros pares en la lista")
            os.execlp("python3","python3","buscaPares.py",str(self.aleatorios),str(self.cantidad))
            sys.exit(0)


        pid2 = os.fork()
        if(pid2==0):
            print ("\t",os.getpid(),": Metodo para encontrar los numeros impares en la lista")
            os.execlp("python3","python3","buscaImpares.py",str(self.aleatorios),str(self.cantidad))
            sys.exit(0)
       


        pid3 = os.fork()
        if(pid3==0):
            print ("\t",os.getpid(),": Metodo para encontrar los numeros primos en la lista")
            os.execlp("python3","python3","buscaPrimos.py",str(self.aleatorios),str(self.cantidad))
            sys.exit(0)

        pid4 = os.fork()
        if(pid4==0):
            print ("\t",os.getpid(),": Metodo para encontrar los numeros perfectos en la lista")
            os.execlp("python3","python3","buscaPerfectos.py",str(self.aleatorios),str(self.cantidad))
            sys.exit(0)

            
        hijo1 = os.wait()
        hijo2 = os.wait() 
        hijo3 = os.wait()
        hijo4 = os.wait()
        if(hijo1):
            print (os.getpid(),": Mi hijo ",hijo1," ha finalizado")
        if(hijo2):
            print (os.getpid(),": Mi hijo ",hijo2," ha finalizado")
        if(hijo3):
            print (os.getpid(),": Mi hijo ",hijo3," ha finalizado")
        if(hijo4):
            print (os.getpid(),": Mi hijo ",hijo4," ha finalizado")
       


            
       

##
# Metodo Main
##
def main():
    tiempoI = time()
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
    tiempoF = time()
    print(os.getpid()," EL tiempo de ejecucion fue: ",tiempoF-tiempoI," segundos")
    

main()
        
   
    
    
        

   

    



   
