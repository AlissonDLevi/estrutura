#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
  int id;
  char *nome;
  float nota;
}*Aluno;

Aluno criarAluno(int a, char *b, unsigned short c) {
  Aluno A = (Aluno)malloc(sizeof(struct aluno));
  A->id = a;
  A->nome = b;
  A->nota = c;
  return A;
}

void modificarNota(Aluno A, float novaNota) { A->nota = novaNota; }


typedef struct node {
  Aluno A;
  struct node *esq;
  struct node *dir;
}*No;

typedef No noRaiz;

int main() {
  noRaiz criarArvore();
  noRaiz criarArvore(Aluno);
  void inOrdemInt(noRaiz);

  Aluno K = criarAluno(10, "Kennedy Lopes\0", 9.);
  No raiz = malloc(sizeof(struct node));
  raiz->esq = 0;
  raiz->dir = 0;
  raiz->A = K;

  Aluno B = criarAluno(12, "franco\0", 9.);
  Aluno C = criarAluno(15, "jose\0", 8.);
  Aluno D = criarAluno(8, "anna\0", 7.);

  noRaiz r = criarArvore(B);
  r->dir = criarArvore(C);
  r->esq = criarArvore(D);

  inOrdemInt(r);
}

noRaiz criarArvore(Aluno A) {
  noRaiz raiz = (No)malloc(sizeof(struct node));
  raiz->A = A;
  raiz->dir = 0;
  raiz->esq = 0;
  return raiz;
}

void inOrdemInt(noRaiz raiz) {
  if (raiz != 0) {
    inOrdemInt(raiz->esq);
    printf("\n%s", raiz->A->nome);
    inOrdemInt(raiz->dir);
  }
}