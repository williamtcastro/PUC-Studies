#include <stdio.h>
#define LIMITE 18

int main(){
    int idade;
    printf("Digite uma idade: ");
    scanf("%d", &idade);
    getchar();
    if (idade >= LIMITE) {
        printf("Maior de idade\n");
    }else{
        printf("Menor de idade\n");
    }
}