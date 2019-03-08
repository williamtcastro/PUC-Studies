#include <stdio.h>

int main(){

    int dia = 28;
    double PI = 3.14159265359;

    printf("Meu\tprimeiro\tprograma");
    printf("\a\a\a\a\a\n");
    printf("Valor da variavel dia: \t%d\n", dia);
    printf("Meu primeiro programa é:\n");
    dia = 01;
    printf("Valor da variavel dia: \t%02d\n", dia);
    printf("Valor da variavel PI: \t%f\n", PI);
    printf("Valor da variavel PI COMPLETO: \t%2.11f\n", PI);
    printf("Valor da variavel PI (3 casas depois da virgula): \t%2.3f\n", PI);
    // printf("%d\n", dia);
    return(0);
}

//  \a == Alert (Sound)
//  \t == Tab
// \n == New Line
//  \b == Backspace
// \r == Carrege return
// \v so ira funcionar com linux


// %d ==  digit
// %2d == 2digits formatacao
// %02d == 02 digits
