#include <stdio.h>
#define REFERENCIA 0

void np(void);

int main(){
    np();
    return(0);
}

// FUNCOES
void np(){
    float valor;
    printf("Digite um numero: ");
    scanf("%f", &valor);
    getchar();
    if (valor >= REFERENCIA) {
        printf("\nVALOR POSITIVO\n");
    }else{
        printf("\nVALOR NEGATIVO\n");
    }
    return;
}