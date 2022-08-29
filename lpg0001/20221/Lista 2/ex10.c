#include <stdio.h>

/*
  Exercício 10
  Faça um programa que leia um inteiro n e utilize uma função (faça as versões
  iterativa e recursiva) para calcular o somatório que determina o valor da
  constante e:
  \sum_{n=0}^\infty 1/n!=1/0!+1/1!+1/2!+...+1/n!+...
*/

float soma_e_iterativa(int n) {
  int i;
  float soma=0;
  float termo=1;

  for (i=0;i<=n;i++) {
    soma+=termo;
    termo/=(i+1);
  }
  return soma;
}

float soma_e_recursiva(int n, int iter, float soma, float termo) {
  //a soma é feita com índices de 0 a n
  //iter é quantos índices já foram somados
  //soma é o valor guardado da soma de k=0 a iter
  //termo é o próximo termo a ser somado
  if (iter>=n) {//caso já tenhamos passado
    return soma;
  }

  return soma_e_recursiva(n,iter+1,soma+termo,termo/(iter+1));
}

int main() {
  printf("%.15lf",soma_e_recursiva(400,0,0,1));
  return 0;
}
