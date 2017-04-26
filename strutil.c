#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char* str, char sep){

    size_t largo = strlen(str);
    char buffer[largo]; //El largo maximo es el numero de caracteres (Ningun separador)
    char** strv = malloc(sizeof(char*) * (largo+1)); //El largo maximo es el numero de caracteres (Un se parador cada un caracter) + NULL del final
    if (!strv)
        return NULL;

    int count = 0;
    for (int i = 0, j = 0; i <= largo; ++i, ++j) {

        if(str[i] == sep || str[i] == '\0'){
            buffer[j] = '\0';
            //TOODO: NO USAR STRLEN! -> EL TAMAÑO ES LA VARIABLE J
            strv[count] = malloc(sizeof(char) * (strlen(buffer) + 1 )); //Largo del buffer + '\0'
            if(!strv[count]){
                while (count > 0){
                    count --;
                    free(strv[count]);
                }
                free(strv);
            }
            strcpy(strv[count], buffer);
            count ++;
            j = -1; //++j lo va a poner en cero
            continue;
        }

        buffer[j] = str[i];
    }
    strv[count] = NULL; //Marco el final
    return strv;
}

char* join(char** strv, char sep){
    if (!strv)
        return "";
    int count = 0;
    char* buffer = strv[count];
    char* output = malloc(sizeof(char) * 99); //TODO: CHANGE THIS SHIT
    *output = '\0';
    char separator[2] = {sep, '\0'};
    while (buffer){
        strcat(output, buffer);
        count ++;
        buffer = strv[count];
        if(buffer)
            strcat(output, separator);
    }
    return output;
}

void free_strv(char *strv[]){
    int count = 0;
    char* a = strv[count];
    while (a){
        free(a);
        count ++;
        a = strv[count];
    }
    free(strv);
}

int main(void){
    char **palabras = split(",a,b,c,de,faaaa,ghi,jkl,", ',');
    char *otro_resultado = join(palabras, ',');  // "Hola,mundo"
    printf("%s",otro_resultado);
    printf("\n");

    //free(palabras[0]);
    //free(palabras);
    free_strv(palabras);
    free(otro_resultado);

    return 0;
}