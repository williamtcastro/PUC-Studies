#include <stdio.h>
#define REFERENCIA 0

int main(){
    float valor;
    printf("Digite um numero: ");
    scanf("%f", &valor);
    getchar();
    if (valor >= REFERENCIA) {
        printf("\nPOSITIVO\n");
    }else{
        printf("\nNEGATIVO\n");
    }
}