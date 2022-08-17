#include <stdio.h>

/*
  Exercício 9
  Faça um programa que leia um inteiro n e utilize uma função (faça as versões
  iterativa e recursiva) para determinar a soma S da série harmônica definida a
  seguir:
  S=1+(1/2)+(1/3)+(1/4)+...+(1/n)
*/

float serie_harmonica_iterativa(int n) {
  if (n<=0) {printf("Erro: argumento invalido.\n"); return 0;}

  int i;
  float soma=0;
  for (i=1;i<=n;i++) {
    soma+=1.0/i;
  }
  return soma;
}

float serie_harmonica_recursiva(int n) {
  if (n<=0) {printf("Erro: argumento invalido.\n"); return 0;}
  if (n==1) {return 1.0;}

  return (1.0/n)+serie_harmonica_recursiva(n-1);
}

int main() {
  printf("%.15f",serie_harmonica_recursiva(10));
  return 0;
}
