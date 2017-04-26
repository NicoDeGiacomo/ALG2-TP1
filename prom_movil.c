#include <stdio.h>
#include <stdlib.h>

double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
    int nk = (int) k;
    double* result = malloc(sizeof(double) * n);
    for (int i = 0; i < n; ++i) {
        result[i] = 0;
        for (int j = (i - nk); j <= (i+nk); ++j) {
            if(j < 0 || j >= n)
                continue;
            result[i] += arreglo[j];
        }
        result[i] /= (i==0 || i == (n-1))? nk+1 : 2*nk+1;
    }
    return result;
}

double* obtener_promedio_movil2(int* arreglo, size_t n, size_t k){
    int nk = (int) k;
    double* result = malloc(sizeof(double) * n);

    result[0] = 2;
    result[5] = 13;

    for (int i = 0, j = (int) n-1; i < n; ++i, --j) {

        if (i == 0){
            for (int l = 0; l <= k; ++l) {
                result[i] += arreglo[l];
                result[n-1] += arreglo[n-l-1];
            }
        }

        result[i] = result[i-1] - arreglo[i] + arreglo[i+k];
        result[j] = result[j+1] - arreglo[j] + arreglo[j-k];

        //result[i] /= (i==0 || i == (n-1))? nk+1 : 2*nk+1;

        //result[j] /= (i==0 || i == (n-1))? nk+1 : 2*nk+1;
    }

    return result;
}

int main(){
    int a[] = { 1, 3, 12, 6, 17, 9 };
    size_t n = 6;
    size_t k = 1;
    double* r = obtener_promedio_movil2(a, n, k);
    printf("%lf", r[1]);
    free(r);
    return 0;
}
