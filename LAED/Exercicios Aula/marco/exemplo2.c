#include <stdio.h>

int main(){
    char x = '|', y = '/';

    
    printf("Sequencia de caracteres\n");

    printf("Valor das variaveis : \t%c\t%c\t%c\t%c\n", 124, 47,45,92);    

    if (x > y) {
        printf("\nTESTE EH VERDADEIRO\n");
        printf("X > Y = %d > %d\n", x, y);
        printf("Caracter maior eh : %c\n", x);
    }else{
        printf("TESTE É FALSO");
    }
    return(0);
}