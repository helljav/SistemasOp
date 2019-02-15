import json
import sys
import os
def esPrimo(num):
    if num < 2:     
        return False
    for i in range(2, num):  
        if num % i == 0:    
            return False
    return True    

cont=0
cantidad = json.loads(sys.argv[2])
Lista=json.loads(sys.argv[1])
for i in range(cantidad):
	if (esPrimo(Lista[i])):
		cont += 1

print("\t",os.getpid(),": Se encontraron ",cont," numeros primos en la lista")
