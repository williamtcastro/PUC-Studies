#include <stdio.h>

int main(){
    char c = '*';
    int x, y, i=0;
    printf("Digite a quantidade de linhas >>> ");
    scanf("%i", &x);
    y = x*(-1);
    printf("\n");
    while(i <= x){
        if (x != i){
            printf("%c", c);
            i++;
        }else{
            printf("\n");
            i=0;
            x--;
        }
    }
    return(0);
}