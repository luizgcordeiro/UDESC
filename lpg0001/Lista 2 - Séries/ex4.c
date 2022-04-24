#include <stdio.h>

double xnsobrenfat(double x,int n);/*Função que calcula x^n/n! de modo recursivo
e otimizado*/
double exponencial(double x,int n);/*Função que calcula e^x com aproximação da
série de Taylor usual com n termos de modo recursivo*/
/*É mais fácil resolver o exercício 5 direto e usar x=1 na função acima ;) */

int main() {
  printf("Este programa calcula uma aproximacao para o numero de Euler, e\n"
  "utilizando a serie de Taylor da funcao exponencial ao redor de 0.\n");
  printf("Escolha quantos termos da serie voce quer utilizar na sua aproximacao: ");

  int k;

  scanf("%d", &k);

  printf("A aproximacao de e eh\n");
  printf("%.8lf",exponencial(1,k));

  return 0;
}

double xnsobrenfat(double x,int n) {

  if (n==0) {//Para n=0, x^n/n!=1
    return 1;
  }

  //Para n>=1, x^n/n!=(x/n)*(x/(n-1))*(x/(n-2))...(x/1)
  return (((double)x)/n)*xnsobrenfat(x,n-1);
}

double exponencial(double x, int n) {
  /*A série de Taylor da exponencial é \sum_{k=0}^n x^n/n!
  Somatório feito recursivo do modo óbvio
  */
  if (n==0) {
    return 1;
  }

  return xnsobrenfat(x,n)+exponencial(x,n-1);
}
