#include <stdio.h>

/*
  Questão 5
  Faça um programa que, dados k e n, mostre na tela os n primeiros números
  primos acima de k. A verificação do número (se é ou não é primo) deve ser
  feita através de uma função.
*/

int e_primo(int p);
void mostrar_primos(int k, int n);

int main() {
  int k,n;

  printf("Este programa toma inteiros k e n e mostra os n primeiros primos"
          " logo acima de k.\n");
  printf("Escolha um valor para k: ");
  scanf("%d",&k);
  printf("Escolha um valor para n: ");
  scanf("%d",&n);

  mostrar_primos(k,n);
  return 0;
}

int e_primo(int p) {
  if (p<0) {//Tira o caso negativo
    return e_primo(-p);
  }
  //Considera p=0 separadamente
  if (p==0) {
    return 0;//0 não é primo
  }
  //Caso contrário, temos que ver se algum número entre 2 sqrt(p) divide p
  int k;
  for (k=2;k*k<=p;k++) {
    if (p%k==0) {
      return 0;
    }
  }
  return 1;
}

void mostrar_primos(int k, int n) {
  int mostrados=0,p;

  for (p=k+1;mostrados<n;p++) {
    if (e_primo(p)) {
      mostrados++;
      printf("O %do primo acima de %d e %d.\n",mostrados,k,p);
    }
  }
}
