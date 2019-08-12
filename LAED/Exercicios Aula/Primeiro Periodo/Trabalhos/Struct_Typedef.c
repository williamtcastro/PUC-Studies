#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define QUANT 3

struct notas{
    float n1; 
    float n2; 
    float n3; 
    float n4;
}

struct cadastro{
    char aluno[250]; 
    int ra; 
    conjunto aed; 
    float media;
}

typedef struct notas conjunto;
typedef struct cadastro dados;

int main() {
    dados turma[QUANT];
    float resultado;

    for (int i=0; i<QUANT; i++){
        printf("Digite o nome do aluno: ");
        scanf("%[^\n]s", turma[i].aluno);
        getchar();

        printf("\n\nDigite o RA do aluno: ");
        scanf("%d", &turma[i].ra);
        getchar();
        printf("\n");

        printf("\n\nDigite a nota 1: ");
        scanf("%f", &turma[i].aed.n1);
        getchar();
        printf("\n");

        printf("\n\nDigite a nota 2: ");
        scanf("%f", &turma[i].aed.n2);
        getchar();
        printf("\n");

        printf("\n\nDigite a nota 3: ");
        scanf("%f", &turma[i].aed.n3);
        getchar();
        printf("\n");

        printf("\n\nDigite a nota 4: ");
        scanf("%f", &turma[i].aed.n4);
        getchar();
        printf("\n");
    }

    printf("\n");

    for (int i=0; i<QUANT; i++){
        printf("Aluno: %s " , turma[i].aluno);
        printf(" RA: %d\n" , turma[i].ra);
        printf(" n1: %f\n" , turma[i].aed.n1);
        printf(" n2: %f\n" , turma[i].aed.n2);
        printf(" n3: %f\n" , turma[i].aed.n3);
        printf(" n4: %f\n" , turma[i].aed.n4);
    }

    return(0);
}

