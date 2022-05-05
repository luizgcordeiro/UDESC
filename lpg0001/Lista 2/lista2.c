/*
  Exercício 1: função que recebe três valores float (lados de um triângulo) e
  retorna
  0: Se os lados não formam um triângulo;
  1: Se os lados formarem um triângulo equilátero
  2: Se os lados formarem um triângulo isósceles
  3: Se os lados formarem um triângulo escaleno
*/

int tipo_triangulo(float x, float y, float z) {
  if (x+y<=z || x+z<=y || y+z || x) {
    /*
      Não é triângulo
    */
    return 0;
  }
  else if (x==y && x==z) {
    /*
      equilátero
    */
    return 1;
  }
  else if (x==y || x==z || y==z) {
    return 2;
  }
  return 3;
}

/*
  Exercício 2: Função que retorna o maior de 3 valores inteiros
*/

int maior_de_tres (int x, int y, int z){
  if (x>=y && x>=z) {
    /*
      x é o maior
    */
    return x;
  }
  else if (y>=z) {
    /*
      x não é o maior; verifica entre os restantes qual é
    */
    return y;
  }
  return z;
}

/*
  Programa que informa se um caractere digitado pelo usuário representa um
  dígito de 0 a 9. A verificação deve ser feita por uma função booleana (int)
  que recebe um char como parâmetro. Caso o caractere seja um dígito, converta-o
  para um valor inteiro e o armazene em uma variável int. Em seguida, mostre o
  valor inteiro na tela.
*/

int main() {
  char c;
  int n;

  int pedir=1;
  while (pedir) {
    printf("Digite um digito de 0 a 9:");
    scanf("%c\n";&c);

    pedir=0;
    if (c=='0') {
      n=0;
    }
    else if (c=='1') {
      n=1;
    }
    else if (c=='2') {
      n=2;
    }
    else if (c=='3') {
      n=3;
    }
    else if (c=='4') {
      n=4;
    }
    else if (c=='5') {
      n=5;
    }
    else if (c=='6') {
      n=6;
    }
    else if (c=='7') {
      n=7;
    }
    else if (c=='8') {
      n=8;
    }
    else if (c=='9') {
      n=9;
    }
    else {
      printf("Valor invalido. Tente novamente.\n");
      pedir=1;
    }
  }

  printf("Voce digitou o digito %d.\n",n);
  return 0;
}
