#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filesplit(const char* name, int n){
    FILE* fileRead = fopen(name, "r");

    int len = 6; //'_' + 4 digitos + \0
    char buffer[strlen(name) + len];
    char number[len];
    snprintf(number, sizeof(char) * len, "_%04d", 1);
    strcpy(buffer, name);
    strcat(buffer, number);

    FILE* fileWrite = fopen(buffer, "w");
    int count = 1;
    int c = fgetc(fileRead);
    while (c != EOF){
        fputc(c, fileWrite);
        c = fgetc(fileRead);
        if (!(count % n)){
            fputc('\n', fileWrite);
            fclose(fileWrite);
            //No abro un nuevo archivo si el prox char es un EOF (Para que no quede vacio)
            if (c != EOF){
                snprintf(number, sizeof(char) * len, "_%04d", count/n+1);
                strcpy(buffer, name);
                strcat(buffer, number);
                fileWrite = fopen(buffer, "w");
            }
        }
        count++;
    }
    fclose(fileWrite);
    fclose(fileRead);

}

int main(int argc, char const *argv[]){
    if (argc > 3 || argc < 3 ){
        fprintf(stderr, "Cannot process more than 2 arguments\n");
        return 1;
    }
    fixcol(argv[1], atoi(argv[2]));
    return 0;
}
