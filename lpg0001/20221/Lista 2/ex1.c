#include <stdio.h>

/*
  Exercício 1: função que recebe três valores float (lados de um triângulo) e
  retorna
  0: Se os lados não formam um triângulo;
  1: Se os lados formarem um triângulo equilátero
  2: Se os lados formarem um triângulo isósceles
  3: Se os lados formarem um triângulo escaleno
*/

int tipo_triangulo(float x, float y, float z);

int main() {
  float x,y,z;
  printf("Escolha um valor para x, y e z:\n");
  printf("x=");
  scanf("%f",&x);
  printf("y=");
  scanf("%f",&y);
  printf("z=");
  scanf("%f",&z);

  int tipo=tipo_triangulo(x,y,z);

  if (tipo==0) {
    printf("\nEsses valores nao formam os lados de um triangulo.");
    return 0;
  }

  printf("\nEsses valores formam os lados de um triangulo ");
  if (tipo==1) {
    printf("equilatero.");
  }
  else if (tipo==2) {
    printf("isosceles.");
  }
  else {
    printf("escaleno.");
  }

  printf("\n");
  return 0;
}
int tipo_triangulo(float x, float y, float z) {
  if (x+y<=z || x+z<=y || y+z <= x || x<=0 || y<=0 || z<= 0) {
    /*
      Não é triângulo
    */
    return 0;
  }
  else if (x==y && x==z) {
    /*
      equilátero
    */
    return 1;
  }
  else if (x==y || x==z || y==z) {
    return 2;
  }
  return 3;
}
