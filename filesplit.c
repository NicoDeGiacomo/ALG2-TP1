//Nombre: Nicolás De Giácomo
//Padron: 99702
//Corrector: Matias Cano
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LEN 6 //'_' + 4 digitos + \0

int filesplit(const char* name, int n){
    FILE* fileRead = fopen(name, "r");
    if (!fileRead) {
        fprintf(stderr, "Error opening the file\n");
        return 1;
    }


    int count = 1;
    while (!feof(fileRead)){
        //Leo una linea de n chars
        char linea[n];
        size_t leidos = fread(linea, sizeof(char), (size_t) n, fileRead);

        //Guardo en un archivo
        char buffer[strlen(name) + FILENAME_LEN];
        char number[FILENAME_LEN];
        snprintf(number, sizeof(char) * FILENAME_LEN, "_%04d", count);
        strcpy(buffer, name);
        strcat(buffer, number);

        FILE* fileWrite = fopen(buffer, "w");
        if (!fileWrite) {
            fclose(fileRead);
            fprintf(stderr, "Error creating a file\n");
            return 1;
        }
        fwrite(linea, sizeof(char), (size_t) leidos, fileWrite);
        count++;
        fclose(fileWrite);

    }

    fclose(fileRead);
    return 0;
}

int main(int argc, char const *argv[]){
    if (argc != 3){
        fprintf(stderr, "Please provide 2 arguments\n");
        return 1;
    }

    return filesplit(argv[1], atoi(argv[2]));
}
