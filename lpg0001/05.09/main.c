#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 4//Numero de colunas das matrizes teste
#define M 4//Numero de linhas das matrizes teste
#define K 1000//Ordem dos numeros aleatorios a serem criados

int maximo(int m, int n);
int numero_de_digitos(int m);
int pot(int m,int k);
void imprimir_matriz(int * a,int m, int n);
void transposicao(int * x, int * y, int m, int n);
float media_pares(int *x ,int m,int n);

int main() {

  srand(time(NULL));   // Initialization, should only be called once.

  int m[M][N];

  int i,j;
  for (i=0;i<M;i++) {
    for (j=0;j<N;j++) {
      m[i][j]=rand()%K-(K/2);
    }
  }

  printf("A matriz eh\n");
  imprimir_matriz(*m,M,N);


  printf("\n");
  printf("A transposta eh\n");
  int t[N][M];
  transposicao(*m,*t,M,N);
  imprimir_matriz(*t,N,M);

  printf("\nA media dos valores pares eh ");
  printf("%f\n",media_pares(*m,M,N));
  return 0;
}

void imprimir_matriz(int * a, int m, int n) {
  int i,j;

  int maiorelemento=0;
  for (i=0;i<m;i++) {
    for (j=0;j<n;j++) {
      maiorelemento=maximo(maiorelemento,abs(a[m*i+j]));
    }
  }

  int k=numero_de_digitos(maiorelemento);//Tem espaço para sinal.
  for (i=0;i<M;i++) {
    for (j=0;j<N;j++) {
      printf("%*d ",k,a[m*i+j]);
    }
    printf("\n");
  }
}

int maximo(int m, int n) {
  if (m>n) {
    return m;
  }
  return n;
}

int pot(int m,int k) {
  if (k==0) {
    return 1;
  }
  return m*pot(m,k-1);
}

int numero_de_digitos(int m) {
  int i=0;
  while (pot(10,i)<m) {
    /*Se sai em i=1, tem 1 dígito; se sai em i=2, tem 2...*/
    i++;
  }
  return i+1;//Tem espaço para o sinal;
}


void transposicao(int * x, int * y, int m, int n) {
  /*Transpõe a matriz em x e grava o resultado em y*/

  int i,j;
  for (i=0;i<m;i++) {
    for (j=0;j<n;j++) {
      y[n*j+i]=x[m*i+j];
    }
  }
}

float media_pares(int *x ,int m,int n) {
  int i,j,soma=0,cont=0;

  for (i=0;i<m;i++) {
    for (j=0;j<n;j++) {
      if (x[m*i+j]%2==0) {
        cont++;
        soma+=x[m*i+j];
      }
    }
  }
  if (cont==0) {
    printf("Erro: sem numeros pares.");
    return (float)0;
  }

  return (float)soma/cont;
}
