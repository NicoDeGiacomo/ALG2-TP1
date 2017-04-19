#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    //TODO: Refactor

	if (argc > 3){
        //TODO: Print invalid arguments ?
        return 0;
    }


    int n = atoi(argv[2]);
    FILE* fileRead = fopen(argv[1], "r");
    int c = fgetc(fileRead);

    size_t len = strlen(argv[1]) + 1 + 4 + 1;
    char number[6]; // The number for the filename buffer
    char buffer[len]; // The filename buffer. Size: FileName + '_' + 4 digit number + \0
    snprintf(number, sizeof(char) * len, "_%04d", 1);

    strcpy(buffer, argv[1]);
    strcat(buffer, number);



    FILE* fileWrite = fopen(buffer, "w");
    int count = 1;
    while (c != EOF){
        fputc(c, fileWrite);
        c = fgetc(fileRead);
        if (!(count % n)){
            fputc('\n', fileWrite);
            fclose(fileWrite);

            snprintf(number, sizeof(char) * len, "_%04d", count/n+1);
            strcpy(buffer, argv[1]);
            strcat(buffer, number);

            fileWrite = fopen(buffer, "w");
        }
        count++;
    }
    fclose(fileWrite);
    fclose(fileRead);

	return 0;
}