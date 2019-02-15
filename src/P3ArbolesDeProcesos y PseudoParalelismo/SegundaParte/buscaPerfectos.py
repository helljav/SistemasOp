import json
import os
import sys

def esPerfecto(num):	
	sumatorio=0
	for i in range(1,num):
    		if num%i==0:
        		sumatorio=sumatorio+i
	if sumatorio==num:
		return True
	else:
		return False

cont=0

Lista=json.loads(sys.argv[1])
for i in range(int(sys.argv[2])):
	if esPerfecto(Lista[i]):
		#print(Lista[i])
		cont += 1

print("\t",os.getpid(),": Se encontraron ",cont," numeros perfectos en la lista")