#include <stdio.h>

int main(){
    int numero;
    printf("\nInforme um valor: ");
    scanf("%d", &numero);
    getchar();

    comparar(numero);
    return(0);
}

void comparar(int value){
    int ZERO = 0;
    if (value >= ZERO){
        printf("\nO valor e positivo!");   
    }if (value < ZERO){
        printf("\nO valor e negativo!");
    }
}