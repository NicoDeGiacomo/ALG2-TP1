//Nombre: Nicolás De Giácomo
//Padron: 99702
//Corrector: Matias Cano
#include <stdio.h>
#include <stdlib.h>

int fixcol(const char* name, int n){

    FILE* fileRead = fopen(name, "r");
    if (!fileRead) {
        fprintf(stderr, "Error opening the file\n");
        return 1;
    }

    int count = 1;
    int c = fgetc(fileRead);

    while (c != EOF){
        printf("%c", c);

        if (!(count%n))
            printf("\n");
        if (c == '\n')
            count = 1;
        else
            count++;

        c = fgetc(fileRead);
    }

    fclose(fileRead);
    return 0;
}

int main(int argc, char const *argv[]){
    if (argc > 3 || argc < 3 ){
        fprintf(stderr, "Please provide 2 arguments\n");
        return 1;
    }
    fixcol(argv[1], atoi(argv[2]));
    return 0;
}
