import os
import time

lines = 40;

while True:
    name = str(input("\n" + ("-"*lines)+ "\n" +"Nome do arquivo: "))
    print(("-"*lines) + "\n")

    # LIMPANDO PROMPT
    os.system("cls")

    print("\n" +name.upper()+ ".c" + "\n")

    # COMPILANDO CODIGO
    print(("-"*lines)+ "\n" +("Compilando codigo") + "\n" + ("-"*lines) + "\n")
    os.system("gcc -o "+name+".exe "+name+".c")
    time.sleep(3)

    # RODANDO O PROGRAMA
    print(("-"*lines)+ "\n" +("Rodando programa") + "\n" + ("-"*lines) + "\n")
    os.system(name+".exe")
