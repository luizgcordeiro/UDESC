#include <stdio.h>

/*Copia e cola coisas do exercício 6 ;)  */

double xnsobrenfat(double x,int n);/*Função que calcula x^n/n! de modo recursivo
e otimizado*/
double cosseno(double x,int n);/*Função que calcula cos(x) com aproximação da
série de Taylor usual com n termos de modo recursivo*/
double potenciademenos1(int n);/*Codigozinho pra (-1)^n*/

int main() {
  printf("Este programa calcula uma aproximacao cos(x), \n"
  "utilizando a serie de Taylor da funcao cosseno ao redor de 0.\n");
  printf("Escolha o grau da serie voce quer utilizar na sua aproximacao: ");

  int k;
  scanf("%d", &k);

  printf("\nE o numero x: ");

  double x;
  scanf("%lf", &x);

  printf("cos(%lf) eh aproximadamente\n",x);
  printf("%.8lf",cosseno(x,k));

  return 0;
}

double xnsobrenfat(double x,int n) {

  if (n==0) {//Para n=0, x^n/n!=1
    return 1;
  }

  //Para n>=1, x^n/n!=(x/n)*(x/(n-1))*(x/(n-2))...(x/1)
  return (((double)x)/n)*xnsobrenfat(x,n-1);
}

double cosseno(double x, int n) {
  /*O termo geral da serie de Taylor do cosseno eh (-1)^nx^(2n)/(2n)!
  Recursivo
  */
  if (n==0) {
    return 1;
  }

  return (potenciademenos1(n)*xnsobrenfat(x,2*n))+cosseno(x,n-1);
}


//Modo fácil de calcular (-1)^n, que é preciso em Nila. Não quero copiar a função de potencia do professor ;)....
double potenciademenos1(int n) {
  if (n%2==1) {//Caso n impar
    return -1;
  }
  return 1;//Caso par
}
