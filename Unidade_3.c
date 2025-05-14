#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void rotas() {
  FILE *f = fopen("tourar9152.tour", "r");
  int a, b;
  fscanf(f, "%d", &a);
  fscanf(f, "%d", &b);
  while (!feof(f)) {
    printf("Rotas %d %d\n", a, b);
    a = b;
    fscanf(f, "%d", &b);
  }
  fclose(f);
}



int main() {
  FILE *arquivo = fopen("ar9152.tsp", "r");
  int c;
  float la;
  float lg;
  int N = 9152;
  double cidLa[N];
  double cidLg[N];

  double *grafo;
  grafo = (double *)malloc(N * N * sizeof(double));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      grafo[i * N + j] = 0.;
    }
  }

  int k = 0;
  while (!feof(arquivo)) {
    fscanf(arquivo, "%d %f %f", &c, &la, &lg);
    cidLa[k] = la;
    cidLg[k] = lg;
    k++;
  }
  fclose(arquivo);
  float maior, menor;
  maior = 0;
  menor = sqrt(pow(cidLa[0] - cidLa[1], 2) + pow(cidLg[0] - cidLg[1], 2));
  int Maior = 0;
  int Menor = 1;
  int contador = 0;
  float dtotal=0;
float media;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      grafo[i * N + j] =
          sqrt(pow(cidLa[i] - cidLa[j], 2) + pow(cidLg[i] - cidLg[j], 2));
      if (grafo[i * N + j]!=0){
        contador++;

        dtotal += grafo[i * N + j];
      }
      if (grafo[i * N + j]>maior){
        maior = grafo[i * N + j];
        Maior = i * N + j;
      }
      if (grafo[i * N + j]<menor && grafo[i * N + j]!=0 ){
        menor = grafo[i * N + j];
        Menor = i * N + j;
        }
    }
  }
  media = (float) dtotal/ (float) contador;
  printf(" maior = %f \n menor = %f \n media = %f \n total = %f \n",maior,menor,media, dtotal);
  
}//teste 