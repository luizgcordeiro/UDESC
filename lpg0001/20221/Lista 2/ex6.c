#include <stdio.h>

/*
  Exercício 6
  Faça um programa que mostre na tela os n primeiros termos da sequência de
  Fibonacci. Por exemplo, dado n = 8, temos: 1, 1, 2, 3, 5, 8, 13 e 21. A
  determinação do n-ésimo termo da sequência deve ser feita por uma função
  iterativa que tem o seguinte protótipo:
  int fibo(int n);
*/

int fibo(int n);
void mostrar_fibo( int n);

int main() {
  printf("Este programa toma um inteiro n e mostra os n primeiros termos\n"
          "da sequencia de Fibonacci.\n");
  printf("Escolha n: ");
  int n;
  scanf("%d",&n);

  mostrar_fibo(n);
  return 0;
}

int fibo(int n) {
  if (n<=0) {
    printf("Erro: argumento negativo.");
    return -1;
  }
  if (n==1 || n==2) {
    return 1;
  }
  int a=1,b=1,x,i;
  for (i=2;i<n;i++) {
    //Calcula o proximo termo, sem gastar mais uma variavel
    b+=a;
    a=b-a;
  }
  return b;
}

void mostrar_fibo( int n) {
  if (n<=0) {
    printf("Erro: argumento negativo.");
    return;
  }

  int i;
  for (i=1;i<=n;i++) {
    printf("%do termo da seq. de Fibonacci: %d\n",i,fibo(i));
  }
  return;
}
