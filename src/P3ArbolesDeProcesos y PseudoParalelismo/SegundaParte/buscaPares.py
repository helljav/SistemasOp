import json
import sys
import os
contador =0
Lista=json.loads(sys.argv[1])
cantidad = json.loads(sys.argv[2])
for i in range (cantidad):
    if(Lista[i]%2 ==0):
        contador = contador+1

print("\t",os.getpid(), "Se encontraron ",contador," numeros pares en la lista")