 #include <stdio.h>
# include <stdlib.h>
# include <time.h>

float mediaIterativa(float V[], int n){
    float soma = 0;
    for (size_t i = 0; i < n; i++)
    {
        soma += V[i];
    }
    return soma / n;
}

float mediaRecursiva(float V[], int n){
    if(n == 1){
        return V[0];
    } else{
        return (V[n-1] + (n-1)*mediaRecursiva(V, n-1)) / n;
    }
}
float * gerador ( size_t n, int seed ) {
    srand ( seed );
    float * res = malloc ( n * sizeof ( int ));
    for ( size_t i = 0; i < n ; i ++) {
        res [ i ] = rand () % 10;
    }
    return res ;
}

int main () {
    size_t n = 10;
    float *aleatorios = gerador (n, time(NULL));
    float resRecursiva = mediaRecursiva(aleatorios, n);
    float resIterativa = mediaIterativa(aleatorios, n);
    printf("A média Recursiva é %f\n", resRecursiva);
printf("A média Iterativa é %f\n", resIterativa);
}
