#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

    if (argc > 3 || argc < 3 ){
        fprintf(stderr, "Cannot process more than 2 arguments");
        return 1;
    }

    int n = atoi(argv[2]);
    FILE* fileRead = fopen(argv[1], "r");

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