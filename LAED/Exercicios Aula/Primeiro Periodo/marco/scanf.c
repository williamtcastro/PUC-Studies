#include <stdio.h>

int main(){
    int i = 2;
    char a;
    float pi = 3.14159265359; 
    printf("Digite um caractere: ");
    scanf("%c", &a);
    getchar();

    printf("\nTipos de dados e formatacoes\n--------------------------|-------\nTipo inteiro:\t\t\t\b\b\b\b\b\b|%3d\nTipo caractere:\t\t  |%3c\nTipo ponto flutuante:\t\t\b\b\b\b\b\b|%7.3f\n", i, a, pi);
    return(0);
}