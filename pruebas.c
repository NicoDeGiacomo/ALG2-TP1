#include <stdbool.h>
#include "strutil.c"
#include "prom_movil.c"

int main(){

    size_t n = 100000;
    size_t k = 1000;
    int a[n];
    for (int j = 0; j < n; ++j)
        a[j] = j;

    double* r = obtener_promedio_movil(a, n, k);
    double* s = obtener_promedio_movil2(a, n, k);
    bool isok = true;
    for (int i = 0; i < n; ++i)
        if (r[i] != s[i]){
            isok = false;
            break;
        }
    printf("Prueba promedios: %s \n", isok ? "OK" : "ERROR");
    free(r);
    free(s);

    char* cadena[] = {",a,akkkkkndiyeb,b,c,de,faaaa,ghi,jkl,", "", ",", "asd", ",,,"};

    for (int i = 0; i < 4; ++i) {
        char **palabras = split(cadena[i], ',');
        char *otro_resultado = join(palabras, ',');
        printf("Prueba con cadena: '%s' -- %s \n", cadena[i], (strcmp(cadena[i], otro_resultado)) ? "ERROR" : "OK");
        free_strv(palabras);
        free(otro_resultado);
    }

    return 0;
}
