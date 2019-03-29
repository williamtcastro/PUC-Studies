#include <stdio.h>
#define REFERENCIA 0
short int np(float);

int main(){
    float valor;
    printf("Digite um numero: ");
    scanf("%f", &valor);
    getchar();
    int val= np(valor);
    return(0);
}

// FUNCOES
short int np(float valor){
    if (valor >= REFERENCIA) {
        printf("\nVALOR POSITIVO");
        return(1);
    }else{
        printf("\nVALOR NEGATIVO");
        return(-1);
    }
    return(0);
}