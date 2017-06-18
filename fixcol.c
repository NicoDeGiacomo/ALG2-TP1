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

    int count = 0;
    while (!feof(fileRead)){
        char linea[n];
        size_t leidos = fread(linea, sizeof(char), (size_t) n, fileRead);

        for (int i = 0; i < leidos; ++i) {
            printf("%c",linea[i]);
            count++;
            if (count == leidos){
                printf("\n");
                count = 0;
            }
            if (linea[i] == '\n')
                count = 0;
        }
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
