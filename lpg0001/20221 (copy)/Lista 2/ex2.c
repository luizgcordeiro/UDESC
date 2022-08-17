#include <stdio.h>

/*
  Exercício 2: Função que retorna o maior de 3 valores inteiros
*/

int maior_de_tres (int x, int y, int z){
  if (x>=y && x>=z) {
    /*
      x é o maior
    */
    return x;
  }
  else if (y>=z) {
    /*
      x não é o maior; verifica entre os restantes qual é
    */
    return y;
  }
  return z;
}
