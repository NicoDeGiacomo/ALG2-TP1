#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
	if (argc > 3 || argc < 3 ){
        printf("Se han recibido %d argumentos", argc);
        return 1;
    }
    int n = atoi(argv[2]);
    FILE* fileRead = fopen(argv[1], "r");

    int len = 6; //'_' + 4 digitos + \0
    char buffer[strlen(argv[1]) + len];
    char number[len];
    snprintf(number, sizeof(char) * len, "_%04d", 1);
    strcpy(buffer, argv[1]);
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
                strcpy(buffer, argv[1]);
                strcat(buffer, number);
                fileWrite = fopen(buffer, "w");
            }
        }
        count++;
    }
    fclose(fileWrite);
    fclose(fileRead);

	return 0;
}