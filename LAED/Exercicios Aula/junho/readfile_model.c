#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void advance_cursor();

int main(void){
    FILE *fd;
    char caracter, thefile[] = "arquivo.txt";
    int i = 0;

    fd = fopen(thefile, "r");

    if (fd == NULL){
        printf("\nErro ao abrir o arquivo: %s\n\n", thefile);
        exit(0);
    }

    do {
        if ((caracter = fgetc(fd)) != EOF){
            putc(caracter, stdout);
        }
    } while (caracter != EOF);
    
    fclose(fd);
    printf("\nFim do programa.....");

    for (i = 10; i; i--){
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