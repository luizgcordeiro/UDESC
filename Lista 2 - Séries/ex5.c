#include <stdio.h>

/*Copia e cola o exercício anterior e faz as alterações devidas*/

double xnsobrenfat(double x,int n);/*Função que calcula x^n/n! de modo recursivo
e otimizado*/
double exponencial(double x,int n);/*Função que calcula e^x com aproximação da
série de Taylor usual com n termos de modo recursivo*/

int main() {
  printf("Este programa calcula uma aproximacao para um numero do tipo e^x,\n"
  "utilizando a serie de Taylor da funcao exponencial ao redor de 0.\n");
  printf("Escolha o grau da serie voce quer utilizar na sua aproximacao: ");

  int k;
  scanf("%d", &k);

  printf("\nE o numero x: ");

    double x;
    scanf("%lf", &x);

  printf("e^%lf eh aproximadamente\n",x);
  printf("%.8lf",exponencial(x,k));

  return 0;
}

//Função que calcula x^n/n! de modo recursivo
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
