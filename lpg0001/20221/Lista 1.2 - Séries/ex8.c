#include <stdio.h>

/*As séries dos exercícios 3 a 7 já foram implementadas de modo recursivo.
Falta só série harmônica e harmônica alternada*/

double potenciademenos1(int n);/*Codigozinho pra (-1)^n*/
double harmonica(int n);/*Serie harmonica*/
double harmonica_alt(int n);/*Serie harmonica alternada*/

int main() {
  printf("Este programa calcula as n-esimas somas parciais das series\n"
  "harmonica e harmonica alternada.\n\n");

  int i;

  /*for (i=0;i<=20;i++) {
    printf("%.8lf\n",harmonica_alt(i));
  }*/

  printf("Escolha n=");
  int n;
  scanf("%d", &n);

  printf("\nSerie harmonica: %.8lf\n",harmonica(n));
  printf("\nSerie harmonica alternada: %.8lf\n",harmonica_alt(n));

  return 0;
}

double harmonica(int n) {
  /*O termo geral da serie harmonica e 1/n; começa em 1;
  Ou, equivalentemente, começa em 0 com valor 0
  */
  if (n==0) {
    return 0;
  }

  return ((double)1)/n + harmonica(n-1);
}

double harmonica_alt(int n) {
  /*O termo geral da serie harmonica e (-1)^n1/n; começa em 1;
  Ou, equivalentemente, começa em 0 com valor 0
  */
  if (n==0) {
    return 0;
  }

  return potenciademenos1(n+1)/n + harmonica_alt(n-1);
}

//Modo fácil de calcular (-1)^n, que é preciso em Nila. Não quero copiar a função de potencia do professor ;)....
double potenciademenos1(int n) {
  if (n%2==1) {//Caso n impar
    return -1;
  }
  return 1;//Caso par
}
