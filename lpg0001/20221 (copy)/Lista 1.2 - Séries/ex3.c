#include <stdio.h>

double GregNew( int n );//Série de GregoryNewton, implementada recursivamente
double Nila( int n );//Série de Nilakantha, implementada recursivamente
double potenciademenos1(int n);/*Codigozinho pra (-1)^n*/

int main() {
  printf("Escolha o método que você quer usar para calcular pi:\n"
  "Gregory-Leibniz (G) ou Nilakantha (N)? ");
  char tipo;

  scanf("%c", &tipo);

  printf("Quantos termos da série associada você quer usar? ");

  int k;

  scanf("%d", &k);

  if (tipo=='G' || tipo=='g') {
    printf("A aproximacao de pi pelo metodo eh\n");
    printf("%.8lf",GregNew(k));
  }
  else if (tipo=='N' || tipo=='n') {
    printf("A aproximacao de pi pelo metodo eh\n");
    printf("%.8lf",Nila(k));
  }
  else {
    printf("Tipo invalido.");
  }

  return 0;
}

//Séries abaixo implementadas do modo recursivo óbvio

double GregNew( int n ) {
  if (n==1) {
    return 4.0;
  }
  else {
    return GregNew(n-1)+potenciademenos1(n-1)*(4.0/(2*n-1));
  }
}

double Nila(int n) {
  if (n==1) {
    return 3;
  }
  else {
    return Nila(n-1)+potenciademenos1(n)*(1.0/((n-1)*(2*n-1)*n));/*o termo '4' no numerador
    simplifica com dois '2' no denominador.*/
  }
}

//Modo fácil de calcular (-1)^n, que é preciso em Nila. Não quero copiar a função de potencia do professor ;)....
double potenciademenos1(int n) {
  if (n%2==1) {//Caso n impar
    return -1;
  }
  return 1;//Caso par
}
