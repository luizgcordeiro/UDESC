#include <stdio.h>

int main() {
  printf("Escolha quantos termos da serie harmonica voce quer ver: ");
  int k;

  scanf("%d", &k);

  int i;
  double soma=0;
  double termo;

  printf("Os %d primeiros termos da serie harmonica sao\n" , k);
  /*Itera tanto a exibição dos termos e já vai somando na série para
  economizar tempo*/
  for (i=1 ; i<=k ; i++) {
    termo=(double)i;//Garante double, não só float
    printf("%.4lf\n" , termo);
    soma+=termo;
  }

  printf("e a soma desses termos e %.4lf\n",soma);
  return 0;
}
