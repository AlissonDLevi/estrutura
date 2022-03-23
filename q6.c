#include <stdio.h>
#include <stdlib.h>

void troca(int v[], int ini, int fim){
    int aux;
    if(ini < fim){
        aux = v[ini];
        v[ini] = v[fim];
        v[fim] = aux;
        troca(v, ini + 1, fim - 1);
    }
}

void imprima(int v[], int tam){
    if(tam == 1)
        printf("%d, ", v[tam - 1]);
    else{
        imprima(v, tam - 1);
        printf("%d, ", v[tam - 1]);
    }
}

int main () {

    int vet[10] = {1,2,3,4,5,6,7,8,9,10};

    imprima(vet, 10);
    troca(vet, 0, 9); 
    printf("\n");
    imprima(vet, 10);

    return 0;
}
