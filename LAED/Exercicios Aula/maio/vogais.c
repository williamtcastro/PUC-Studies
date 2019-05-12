#include <stdio.h>
#include <ctype.h>
#include <string.h>

short int cState(char c);

int main(){
    char name[150], arrayVogals[150];
    int totalLen;
    int cont = 0;
    int c = 0;
    memset(&name, '\0', 150);
    memset(&arrayVogals, '\0', 150);
    printf("Digite seu nome: ");
    scanf("%[^\n]s", name);
    getchar();
    for(int i=0; i<strlen(name); i++){
        if(cState(name[i])){
            arrayVogals[c] = name[i];
            c++;
            cont++;
        }
    }

    printf("\nVogais: %s", arrayVogals);
    printf("\nQuantidade de vogais no seu nome: %d", cont);
    return(0);
}

short int cState(char c){
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'}
    for( int i=0; i<5; i++){
        if(c == vogais[i]){
            return(1);
        }
    }
    return(0);
}