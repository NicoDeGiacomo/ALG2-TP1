#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
    if (k >= n)
        k = n-1;
    int nk = (int) k;
    double* result = malloc(sizeof(double) * n);
    for (int i = 0; i < n; ++i) {
        result[i] = 0;
        for (int j = (i - nk); j <= (i+nk); ++j) {
            if(j < 0 || j >= n)
                continue;
            result[i] += arreglo[j];
        }
        if (i==0 || i == (n-1))
            result[i] /= nk+1;
        else if (i < nk)
            result[i] /= i+k+1;
        else if ((i+nk) > (n-1))
            result[i] /= k+1+(i + nk - n + 1);
        else
            result[i] /= 2*nk+1;
    }
    return result;
}

double* obtener_promedio_movil2(int* arreglo, size_t n, size_t k){
    if (k >= n)
        k = n-1;

    double* result = malloc(sizeof(double) * n);
    double result2[n];
    for (int i = 0; i < n; ++i)
        result[i] = result2[i] = 0;

    int nk = (int) k;

    for (int i = 0, j = (int) n-1; i < n; ++i, --j) {
        if (i <= 0){
            //Las sumas parciales de los extremos se hacen recorriendo
            for (int l = 0; l <= nk; ++l) {
                result[i] += arreglo[l];
                result2[n-1] += arreglo[n-l-1];
            }
            continue;
        }

        //Sumas parciales hacia la derecha (sin volver a recorrer)
        if (i < n-1){
            if (i + nk < n)
                result[i] = result[i-1] - arreglo[i-1] + arreglo[i+nk];
            else
                result[i] = result[i-1] - arreglo[i-1];
        }

        //Sumas parciales hacia la izquierda (sin volver a recorrer)
        if (j > 0){
            if (j-nk >= 0)
                result2[j] = result2[j+1] - arreglo[j+1] + arreglo[j-nk];
            else
                result2[j] = result2[j+1] - arreglo[j+1];
        }

    }

    for (int i = 0; i < n; ++i) {
        result[i] += result2[i];
        if (i != 0 && i != n-1)
            //Ambas sumas parciales (no en los extremos) incluyen al numero del medio,
            // por lo que hay que restarle ese numero una vez
            result[i] -= arreglo[i];

        if (i==0 || i == (n-1))
            result[i] /= nk+1;
        else if (i < nk)
            result[i] /= i+nk+1;
        else if ((i+nk) > (n-1))
            result[i] /= nk+1+(i + nk - n + 1);
        else
            result[i] /= 2*nk+1;
    }

    return result;
}
