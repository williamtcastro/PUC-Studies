#include <stdio.h>
#include <stdlib.h>

#define URNAS_QUANT 3
#define MAX_VOTES 5
#define MAX_OPTIONS 7
#define CANDIDATES_QUANT 6

unsigned int candidates[CANDIDATES_QUANT] = {10, 20, 30, 0, 99};
unsigned int urnas[URNAS_QUANT][MAX_VOTES];
char options[MAX_OPTIONS][255]= {"\n[ 1 ] - Definir votos das 3 urnas sequencialmente." , 
                                        "[ 2 ] - Definir votos de uma urna especifica.", 
                                        "[ 3 ] - Listar os votos de todas as urnas.",
                                        "[ 4 ] - Contabilizar o resultado de votos de cada candidato considerando todas as urnas e exibir o resultado.",
                                        "[ 5 ] - Exibir o total de votos de um candidato especifico.",
                                        "[ 6 ] - Fim."};

unsigned int setStdValue_int = 0;
unsigned int voteValidation(unsigned int);
void voteRegister(unsigned int, unsigned int);
void choseAction(unsigned int);
void showResults(void);
void callError(void);
void setStdValue(void);
void setVoteTo();
void candidateTotalVotes(void);

int main(){
    setStdValue(); 
    unsigned int c_option;
    for (size_t option = 0; option < MAX_OPTIONS; option++){
        printf("%s\n", options[option]);    
    }
    printf("\nDigite sua opcao >>> ");
    scanf("%d", &c_option);
    getchar();
    printf("\n");
    choseAction(c_option);
    return(0);
}

void choseAction(unsigned int c_option){
    switch (c_option){
    case 1:
        voteRegister(1, 0);
        break;
    
    case 2:
        setVoteTo();
        break;

    case 3:
        showResults();
        break;
    
    case 4:
        callError();
        break;
    
    case 5:
        candidateTotalVotes();
        break;
    
    case 6:
        printf("O programa sera finalizado!");
        exit(0);
        break;

    default:
        break;
    }
}

void voteRegister(unsigned int type, unsigned int urna){
    unsigned int vote;
    switch (type){
    case 1:
        for (size_t i_urna = 0; i_urna < URNAS_QUANT; i_urna++){
            printf("Digite seu voto para a urna %d.\n", i_urna+1);
            for (size_t i_vote = 0; i_vote < MAX_VOTES; i_vote++){
                vote = voteValidation(i_vote);
                printf("\n");
                urnas[i_urna][i_vote] = vote;
            }
        }
        main();
        break;

    case 2:
        printf("Digite seu voto para a urna %d.\n", urna);
        urna = urna-1;
        for (size_t i_vote = 0; i_vote < MAX_VOTES; i_vote++){
            vote = voteValidation(i_vote);
            printf("\n");
            urnas[urna][i_vote] = vote;
        }
        main();
    break;
    
    default:
        break;
    }
    
    main();
}

unsigned int voteValidation(unsigned int i_vote){
    unsigned int vote;
    printf("Digite seu %d* voto >>> ", i_vote+1);
    scanf("%d", &vote);
    getchar();
    fflush(stdin);
    for (size_t i_candidate = 0; i_candidate < CANDIDATES_QUANT; i_candidate++){
        if (vote == candidates[i_candidate]){
            return(vote);
        }
    }
    voteValidation(i_vote);
    return(0);
}

void setStdValue(){
    if (setStdValue_int == 0){
        for (size_t i_urna = 0; i_urna < URNAS_QUANT; i_urna++){
            for (size_t i_vote = 0; i_vote < MAX_VOTES; i_vote++){
                urnas[i_urna][i_vote] = 1;
            }
        }
        setStdValue_int = 1;
    }
}

void setVoteTo(){
    unsigned int urna;
    printf("Digite a urna que voce deseja votar >>> ");
    scanf("%d", &urna);
    getchar();
    fflush(stdin);
    voteRegister(2, urna);
}

void showResults(){
    for (size_t i_urna = 0; i_urna < URNAS_QUANT; i_urna++){
        printf("\n----------------\nURNA %d\n----------------\n", i_urna+1);
        for (size_t i_vote = 0; i_vote < MAX_VOTES; i_vote++){
            if (urnas[i_urna][i_vote] != 1){
                printf("| %d ", urnas[i_urna][i_vote]);
            }else{
                printf("| N/A ");
            }
        }
        printf("\n");
    }
    main();
}

void candidateTotalVotes(){
    unsigned int votes_total = 0;
    unsigned int candidate;
    printf("Digite o numero do candidato para ver seu total de votos >>> ");
    scanf("%d", &candidate);
    getchar();
    fflush(stdin);
    for (size_t i_candidate = 0; i_candidate < CANDIDATES_QUANT; i_candidate++){
        if (candidate == candidates[i_candidate]){
            for (size_t i_urna = 0; i_urna < URNAS_QUANT; i_urna++){
                for (size_t i_vote = 0; i_vote < MAX_VOTES; i_vote++){
                    if (candidate == urnas[i_urna][i_vote] ){
                        votes_total++;
                    }
                }
            }
        }
        printf("%d", votes_total);
        // if (votes_total != 0){
            printf("\nTotal de votos do %d e igual a | %d |\n", candidate, votes_total);
        // }
        main();
    }
}

void callError(){
    printf("ESCOLHA EM DESENVOLVIMENTO\n");
    main();
}