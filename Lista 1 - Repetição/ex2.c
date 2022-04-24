#include <stdio.h>

int main() {
  printf("Este programa toma 3 números fracionarios e verifica se\n"
  "existe um triângulo que tenha esses numeros como lados, e da algumas\n"
  "informacoes sobre tal triangulo (caso exista).\n\n");
  printf("Digite os tres numeros separados por espacos: ");

  float a,b,c,x;
  scanf("%f %f %f", &a, &b, &c);

  /*Vamos botar o maior valor na primeira entrada*/

  if (b>a) {
    x=a;
    a=b;
    b=x;
  }

  if (c>a) {
    x=a;
    a=c;
    c=x;
  }

  if (a>=b+c) {
    printf("NAO FORMA TRIANGULO. :(((((( \n");
  }
  else if (a*a==b*b+c*c) {
    printf("TRIANGULO RETANGULO.\n");
  }
  else if (a*a>b*b+c*c){
    printf("TRIANGULO OBTUSANGULO.\n");
  }
  else if (a*a<b*b+c*c) {
    printf("TRIANGULO ACUTANGULO.\n");//Nesse caso, pode ser equilatero ou isosceles
    if (a==b && a==c) {//Verifica se os tres coincidem
      printf("TRIANGULO EQUILATERO.\n");
    }
    else if (a==b || a==c || b==c){//Se os três não coincidirem mas dois sim
      printf("TRIANGULO ISOSCELES.\n");
    }
  }

  return 0;
}
