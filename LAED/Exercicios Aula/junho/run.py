import os
import time
import platform

# variables
sys = platform.system()
lines = 40
clear = ''
run = ''

# SYSTEM VIRYFIER
if sys == 'Windows':
    clear = 'cls'
    run = ''
if sys == 'Linux':
    clear = 'clear'
    run = './'

# os.system(clear)
print('Sistema identificado: {}\n'.format(sys.upper()))

while True:

    name = str(input("Digite o nome do arquivo: "))
    print(("-"*lines) + "\n")

    # LIMPANDO PROMPT
    os.system(clear)
    
    print("\nARQUIVO " +name.upper()+ ".C")

    # COMPILANDO CODIGO
    print(("-"*lines)+ "\n" +("COMPILANDO CODIGO") + "\n" + ("-"*lines) + "")
    print(("AVISOS E ERROS DO CODIGO") + "\n" + ("-"*lines) + "")
    os.system("gcc −W −Wall "+name+".c -o "+name+"")
    print(("-"*lines)+ "\n" +"CODIGO COMPILADO" + "\n" + ("-"*lines))

    # RODANDO O PROGRAMA
    print("RODANDO PROGRAMA" + "\n" + ("-"*lines) + "\n")

    os.system(run+name)

    #PROGRAMA FINALIZADO
    print( "\n\n"+("-"*lines)+ "\n" +("PROGRAMA FINALIZADO") + "\n" + ("-"*lines) + "\n")
