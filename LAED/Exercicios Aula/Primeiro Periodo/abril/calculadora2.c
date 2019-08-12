#include <stdio.h>
float subtracao(float, float);
float adicao(float, float);
float divisao(float, float);
float multiplicacao(float, float);

int main(){
    int decisao;
    float valorA, valorB, valorFinal;
    printf("\nDigite\n1- Subtracao\n2- Adicao\n3- Divisao\n4- Multiplicacao\n");
    printf("Digite a operacao que deseja fazer: ");
    scanf("%d", &decisao);
    getchar();
    printf("\nDigite o primeiro numero: ");
    scanf("%f", &valorA);
    getchar();
    printf("\nDigite o segundo numero: ");
    scanf("%f", &valorB);
    getchar();

    switch (decisao){
        case 1:
            valorFinal = subtracao(valorA,valorB);
            break;
    
        case 2:
            valorFinal = adicao(valorA,valorB);
            break;
    
        case 3:
            if(valorB != 0){
                valorFinal = divisao(valorA,valorB);
            }else{
                printf("\nOpercao Invalida!\nDivisao por Zero");
                return(0);
                break;
            }
            break;
    
        case 4:
            valorFinal = multiplicacao(valorA,valorB);
            break;
    
        default:
            printf("\nOpercao  Invalida!");
            return(0);
            break;
    }
    printf("\nResultado -> %.3f",valorFinal);
    return(0);
}

// FUNCOES
float subtracao(float valorA, float valorB){
    float valorFinal = valorA - valorB; 
    return(valorFinal);
}

float adicao(float valorA, float valorB){
    float valorFinal = valorA + valorB;
    return(valorFinal);
}

float divisao(float valorA, float valorB){
    float valorFinal = valorA / valorB;
    return(valorFinal);
}

float multiplicacao(float valorA, float valorB){
    float valorFinal = valorA * valorB; 
    return(valorFinal);
}