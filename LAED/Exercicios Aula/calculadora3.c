#include <stdio.h>
#include <ctype.h>
float subtracao(float, float);
float adicao(float, float);
float divisao(float, float);
float multiplicacao(float, float);
unsigned short int redo();

int main(){
    int decisao, refazer, wrong_choice = 0;
    float valorA, valorB, valorFinal;
    while(redo()){    
        printf("\nDigite\n1- Subtracao\n2- Adicao\n3- Divisao\n4- Multiplicacao\n");
        printf("Digite a operacao que deseja fazer\n>>>> ");
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
        printf("\nResultado -> %.3f\n",valorFinal);
    }
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

unsigned short int redo(){
    unsigned short int result;
    int cont = 0;
    char choice;
    while(cont <=2){
        printf("\nDeseja fazer outro calculo\nDigite 'S' para sim\nDigite 'N' para nao\n>>>> ");
        choice = toupper(getchar());
        if(choice == 'S'){
            return(1);
        }
        if(choice == 'N'){
            return(0);
        }
        ++cont;
    }
}