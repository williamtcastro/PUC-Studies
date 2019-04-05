#include <stdio.h>
short int subtracao(float, float);
short int adicao(float, float);
short int divisao(float, float);
short int multiplicacao(float, float);

int main(){
    int decisao;
    float valorA, valorB;
    printf("\n1- Subtracao\n2- Adicao\n3- Divisao\n4- Multiplicacao\n");
    printf("Digite a operacao que deseja fazer: ");
    scanf("%d", &decisao);
    getchar();
    printf("\nDigite o primeiro numero: ");
    scanf("%f", &valorA);
    getchar();
    printf("\nDigite o segundo numero: ");
    scanf("%f", &valorB);
    getchar();

    if(decisao == 1){
        subtracao(valorA,valorB);
    }
    if(decisao == 2){
        adicao(valorA,valorB);
    }
    if(decisao == 3){
        divisao(valorA,valorB);
    }
    if(decisao == 4){
        multiplicacao(valorA,valorB);
    }
    return(0);
}

// FUNCOES
short int subtracao(float valorA, float valorB){
    float valorFinal = valorA - valorB;  
    printf("\nRultado; %.3f",valorFinal);
    return(valorFinal);
}

short int adicao(float valorA, float valorB){
    float valorFinal = valorA + valorB; 
    printf("\nRultado; %.3f",valorFinal);
    return(valorFinal);
}

short int divisao(float valorA, float valorB){
    float valorFinal = valorA / valorB; 
    printf("\nRultado; %.3f",valorFinal);
    return(valorFinal);
}

short int multiplicacao(float valorA, float valorB){
    float valorFinal = valorA * valorB;  
    printf("\nRultado; %.3f",valorFinal);
    return(valorFinal);
}