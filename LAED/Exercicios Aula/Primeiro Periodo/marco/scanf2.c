#include <stdio.h>

int main(){
    char a;
    printf("Informe um caractere: ");
    scanf("%c", &a);
    
    printf("%c\n", a);
    printf("%d\n", a);

    a = a+1;
    
    printf("%c\n", a);
    printf("%d\n", a);

    return(0);
}
