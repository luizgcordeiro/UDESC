#include <stdio.h>

int main() {
  printf("Este programa verifica a posicao de um ponto (x,y) no plano cartesiano.\n\n");
  printf("Digite x: ");

  float x;
  scanf("%f", &x);

  printf("Digite y: ");

  float y;
  scanf("%f", &y);

  if (x==0 && y==0) {
    printf("Origem");
  }
  else if (x==0) {
    printf("Eixo Y");
  }
  else if (y==0) {
    printf("Eixo X");
  }
  else if (y>0) {
    if (x>0) {
      printf("Q1");
    }
    else {
      printf("Q2");
    }
  }
  else if (x<0) {//Nesse caso, já temos y<0, pois não anterior no anterior
    printf("Q3");
  }
  else {
    printf("Q4");
  }

  printf("\n");//Só porque fica tudo na mesma linha no fim, bem feio

  return 0;
}
