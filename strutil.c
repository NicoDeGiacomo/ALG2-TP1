#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(const char* str, char sep){

    size_t largo = strlen(str);
    char buffer[largo]; //El largo maximo es el numero de caracteres (Ningun separador)

    //Largo: Cantidad de separadores + 1 - Le tengo que sumar otro para el NULL del final
    int cant_sep = 0;
    for (int g = 0; str[g]; g++)
        if(str[g]==sep)
            cant_sep++;
    char** strv = malloc(sizeof(char*) * (cant_sep + 2));
    if (!strv)
        return NULL;

    int count = 0;
    for (int i = 0, j = 0; i <= largo; ++i, ++j) {

        if(str[i] == sep || str[i] == '\0'){
            buffer[j] = '\0';
            strv[count] = malloc(sizeof(char) * (j + 1 )); //Largo del buffer + '\0'
            if(!strv[count]){
                while (count > 0)
                    free(strv[count--]);
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

    int len = 0;
    int count = 0;
    //Tamaño output: suma de todos los largos de las cadenas en strv + cantidad de separadores requeridos
    while (strv[count])
        len += strlen(strv[count++]) + 1;

    count = 0;
    char* buffer = strv[count];
    char* output = malloc(sizeof(char) * len );
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
    char* cadena[] = {",1,akkkkkkbdnskaidhfndiyeb,b,c,de,faaaa,ghi,jkl,", "", ",", "asd"};
    
    for (int i = 0; i < 4; ++i) {
        char **palabras = split(cadena[i], ',');
        char *otro_resultado = join(palabras, ',');
        printf("Prueba con cadena: '%s' -- %s \n", cadena[i], (strcmp(cadena[i], otro_resultado)) ? "ERROR" : "OK");
        free_strv(palabras);
        free(otro_resultado);
    }

    return 0;
}