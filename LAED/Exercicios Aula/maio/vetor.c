#include <stdio.h>
#define TAM 10

int main(){
    int notas[] = {6,8,5,4,7,8,5,7,7,8};
    int auxiliar[TAM], i;
    for(i=TAM-1; i >= 0; i--){
        printf("%d\n", notas[i]);
    }
}