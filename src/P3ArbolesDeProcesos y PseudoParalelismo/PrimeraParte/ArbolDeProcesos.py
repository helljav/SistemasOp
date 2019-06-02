# -*- coding: utf-8 -*-
# C:/Users/HP/Desktop/'Sistemas operativos'/src/'P3ArbolesDeProcesos y PseudoParalelismo'

import os
import sys
import time
import getpass

def main(argv):    
    print("")
    prof = int (input("Proporciona la profundidad: "))    
    ramas = int(input("Proporciona el numero de hojas: "))

    print ("\n UID\t PID\t PPID\t TTY\t\t STIME\t\t COMMAND")

    pid =0
    for i in range(prof):
        for j in range(ramas):
            pid=os.fork()
            if not(pid):
                break
        if(pid!=0):
            break
    print(getpass.getuser(),"\t",os.getpid(),"\t",os.getppid(),"\t",os.ttyname(sys.stdout.fileno()),"\t",os.ctermid(),"\t",argv[0])
    time.sleep(2)



main(sys.argv)
