#include <stdio.h>

/*
  Exercício 8
  Faça um programa que leia um inteiro n e determine a soma S da seguinte forma:
  1 + 2 + 3 + 4 + ... + n.
  Escreva duas versões de funções: iterativa e recursiva.
*/

int soma_inteiros_iterativa(int n);
int soma_inteiros_recursiva(int n);
int soma_inteiros_trivial(int n);

int main() {
  printf("Este programa toma inteiro positivo n e determina a soma\n"
          "dos n primeiros inteiros positivos.\n");
  int n;
  printf("Escolha n: ");
  scanf("%d",&n);

  /*Troque aqui para fazer recursiva, se quiser.*/
  printf("Resultado: %d.\n",soma_inteiros_iterativa(n));
  return 0;
}
int soma_inteiros_iterativa(int n) {
  if (n<=0) {printf("Erro: argumento invalido."); return 0;}

  int i,soma=0;
  for (i=1;i<=n;i++) {
    soma+=i;
  }
  return soma;
}

int soma_inteiros_recursiva(int n) {
  if (n<=0) {printf("Erro: argumento invalido."); return 0;}
  if (n==1) {return 1;}

  return n+soma_inteiros_recursiva(n-1);
}

/*EXTRA*/

int soma_inteiros_trivial(int n) {
  if (n<=0) {printf("Erro: argumento invalido."); return 0;}

  return (n*(n+1))/2;
}
