#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define ALPHABETH_LENTGH 29

void advance_cursor();

int main(void){
    FILE *fd;
    char caracter, thefile[255], alphabeth[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','y','x','w','z',' ','.','?'};
    int i = 0; 
    int letterCount[ALPHABETH_LENTGH];

    for (size_t i = 0; i < ALPHABETH_LENTGH; i++){
        letterCount[i] = 0;
    }
    // printf("%d\n", sizeof(alphabeth));
    printf("Insira o nome do arquivo com sua extensao!!!\n>>> ");
    scanf("%[^\n]s", thefile);
    printf("\n---------------------------------\nConteudo do %s\n---------------------------------\n", thefile);

    fd = fopen(thefile, "r");

    if (fd == NULL){
        printf("\nErro ao abrir o arquivo: %s\n\n", thefile);
        exit(0);
    }
    
    printf("\n");
    do {
        if ((caracter = fgetc(fd)) != EOF){
            putc(caracter, stdout);
            for (int i = 0; i < ALPHABETH_LENTGH; i++){
                if(tolower(caracter) == alphabeth[i]){
                    letterCount[i] +=1;
                }
            }
        }
    } while (caracter != EOF);
    
    printf("\n\n---------------------------------\nHISTOGRAMA DAS LETRAS\n---------------------------------\n");

    for (size_t i = 0; i < ALPHABETH_LENTGH; i++){
        printf("\n%c | ", alphabeth[i]);
        for (size_t z = 0; z < letterCount[i]; z++){
            printf("*");
        }
        printf(" | N = %d", letterCount[i]);
    }

    fclose(fd);
    printf("\n\n---------------------------------\n\nFim do programa.....");

    for (i = 100000; i; i--){
        advance_cursor();
        usleep(100000);
    }

    printf("\n");

    getchar();
    return(0);
}

void advance_cursor() {
    static int pos = 0;
    char cursor[] = {'/', '-', '\\', '|'};

    printf("%c\b", cursor[pos]);
    fflush(stdout);
    pos = (pos+1) % 4;
}