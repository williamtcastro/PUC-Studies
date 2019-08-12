#include <stdio.h>

int main(){
    
    int ZERO = 0;
    int numero;
    printf("\nInforme um valor: ");
    scanf("%d", &numero);
    getchar();

    if (numero >= ZERO){
        printf("\nO valor e positivo!");   
    }if (numero < ZERO){
        printf("\nO valor e negativo!");
    }
    return(0);
}