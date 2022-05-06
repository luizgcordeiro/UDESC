#include <stdio.h>

/*
  Exercício 4
  Faça uma função que recebe 2 parâmetros, x e y, e calcule a soma dos números
  impares entre eles (sem contar com eles mesmos). Repare que a função deve
  levar em conta de que x pode ser maior do que y. Por exemplo, para x = 6 e
  y = -5, temos a seguinte soma (em ordem crescente):
  -3 + (-1) + 1 + 3 + 5 = 5.
  Outro exemplo: para x = 3 e y = 10 temos
  5 + 7 + 9 = 21.
*/

int soma_impares( int n , int m) {
  if (n-m<=1 && m-n<=1) {//Caso base se não tiver espaço entre eles, não retorna nada
    return 0;
  }
  if (m<n) {//Se a segunda entrada for menor, inverte
    return soma_impares(m,n);
  }
  if (m%2==1) {//Se m for ímpar, ignora
    return soma_impares(m+1,n);
  }
  if (n%2==1) {//Mesma coisa pro n
    return soma_impares(m,n-1);
  }
  /*
    Caso restante: m e n pares, e tem um espaço entre eles. Põe o primeiro
    ímpar e soma o resto.
  */
  return m+1+soma_impares(m+2,n);
}
