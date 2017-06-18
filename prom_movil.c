//Nombre: Nicolás De Giácomo
//Padron: 99702
//Corrector: Matias Cano
#include <stdio.h>
#include <stdlib.h>

double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
    double* result = calloc(n, sizeof(double));
    for (int i = 0; i < n; ++i) {
        int cont = 0;
        for (int j = (i - (int)k); j <= (i+(int)k); ++j) {
            //Entra recien en i=1 (Ignora el i=0)
            if(j < 0 || j >= n)
                continue;
            result[i] += arreglo[j];
            cont+=1;
        }
        result[i] /= cont;
    }
    return result;
}

double* obtener_promedio_movil2(int* arreglo, size_t n, size_t k){

    double* result = calloc(n, sizeof(double));
    if (!result)
        return NULL;

    for (int j = 0; j <= k; ++j) {
        result[0] += arreglo[j];
    }
    int cant = k+1;
    int prev = result[0];
    result[0] /= cant;

    for (int i = 1; i < n; ++i) {
        if (i<=k){
            result[i] = prev + arreglo[i + k];
            cant++;
        }
        else if (i + k < n){
            result[i] = prev - arreglo[i - k - 1] + arreglo[i + k];
        }
        else {
            result[i] = prev - arreglo[i - k - 1];
            cant--;
        }

        prev = result[i];
        result[i] /= cant;
    }

    return result;
}
