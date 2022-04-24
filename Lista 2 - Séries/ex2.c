#include <stdio.h>

int main() {
  printf("Escolha quantos termos da serie harmonica alternada voce quer ver: ");
  int k;

  scanf("%d", &k);

  double soma=0;
  double termo;
  double sinal=(double)1;

  int i;

  printf("Os %d primeiros termos da serie harmonica alternada sao\n" , k);
  /*Itera tanto a exibição dos termos e já vai somando na série para
  economizar tempo*/
  for (i=1 ; i<=k ; i++) {
    termo=sinal/i;//sinal já é double
    printf("%.4lf\n" , termo);
    soma+=termo;
    sinal=-sinal;
  }

  printf("e a soma desses termos eh %.8lf\n",soma);
  return 0;
}
