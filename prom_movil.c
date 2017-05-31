//Nombre: Nicolás De Giácomo
//Padron: 99702
//Corrector: Matias Cano
#include <stdio.h>
#include <stdlib.h>

double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
    double* result = calloc(n, sizeof(double));
    for (int i = 0; i < n; ++i) {
        int cont = 0;
        for (int j = (i - k); j <= (i+k); ++j) {
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
    double aux[n];
    double cont[n];
    for (int i = 0; i < n; ++i){
        aux[i] = 0;
        cont[i] = 2*k+1;
    }

    int prev = 0;
    for (int i = 0; i <= k; ++i) {
        prev += arreglo[i];
    }
    prev-=arreglo[0];

    for (int i = 0; i < n; ++i) {
        aux[i] = prev;
        prev -= (i+1<n)?arreglo[i+1]:0;
        prev += (i+k+1<n)?arreglo[i+k+1]:0;
        cont[i]-= (i+k+1<n)?0:(i+k+1-n);
    }

    prev = 0;
    for (int i = n-1; i >= n-k-1; --i) {
        prev += arreglo[i];
    }
    prev-=arreglo[n-1];

    for (int i = n-1; i >= 0; --i) {
        result[i] = arreglo[i] + aux[i] + prev;
        prev -= (i-1>=0)?arreglo[i-1]:0;
        prev += (i-(int)k-1>=0)?arreglo[i-(int)k-1]:0;

        cont[i]+= (i-(int)k>=0)?0:(i-(int)k);
        result[i]/=cont[i];
    }

    return result;
}
