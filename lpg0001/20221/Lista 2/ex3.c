#include <stdio.h>

/*
  Exercício 3

  Programa que informa se um caractere digitado pelo usuário representa um
  dígito de 0 a 9. A verificação deve ser feita por uma função booleana (int)
  que recebe um char como parâmetro. Caso o caractere seja um dígito, converta-o
  para um valor inteiro e o armazene em uma variável int. Em seguida, mostre o
  valor inteiro na tela.
*/

int e_digito (char c);

int main() {
  char c;

  int pedir=1;//Vamos fazer pedir o número até digitar um número
  while (pedir) {
    printf("Digite um digito de 0 a 9: ");
    scanf("%c",&c);//guarda o número
    while (c=='\n') {//Enquanto for só espaço em branco vai dando linha
      scanf("%c",&c);
    }
    if (e_digito(c)) {//se for digito, pára de pedir
      pedir=0;
    }
    else {//Se não for, pede de novo
      printf("\nValor invalido. Tente novamente.\n");
    }
  }

  //Convert o char pra código ascii e subtrai 48.
  printf("Voce digitou o digito %d.\n",(int)c-48);
  return 0;
}

int e_digito (char c) {
  if (c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' ||
    c=='7' || c=='8' || c=='9') {
      return 1;
    }
  return 0;
}
