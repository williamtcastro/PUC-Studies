#include <stdio.h>
int main(){
    int k = 0;
    for(int i = 0; i < 5; i++){
        k +=2*i;
    };
    printf("%d\n", k);
    return(k);
}