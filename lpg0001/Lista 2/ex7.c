#include <stdio.h>

int soma_especial(int n, int k, int x);

/*
  Exercício 7
  Escreva uma função que calcula o somatório dos n termos que são múltiplos de k
  a partir de x. Os parâmetros são determinados pelo usuário e a função é
  chamada pelo programa principal, que em seguida mostra o resultado na tela.
  Exemplo: para n = 3, k = 4 e x = 18, temos, 20 + 24 + 28 = 72.
  Protótipo da função:
  int soma_especial(int n, int k, int x);
*/

int main() {
  printf("Este programa toma inteiro n, k e x e calcula a soma dos n primeiros\n"
          "multiplos de k a partir de x.\n");
  int k,n,x;
  printf("Escolha n: ");
  scanf("%d",&n);
  printf("Escolha k: ");
  scanf("%d",&k);
  printf("Escolha x: ");
  scanf("%d",&x);

  printf("Resultado: %d.\n",soma_especial(n,k,x));
  return 0;
}

int soma_especial(int n, int k, int x) {
  if (n<0 || k==0) {
    printf("Erro: argumentos invalidos.");
    return 0;
  }
  if (n==0) {
    return 0;
  }

  /*Caso n>=1, encontramos o primeiro múltiplo de k logo acima de x, e somamos o
  que falta*/
  return x+k-(x%k)+soma_especial(n-1,k,x+k-(x%k));
}
