#include <stdio.h>

int main() {
  printf("Digite um inteiro N. Após isso, digite outros N números inteiros.\n\n"
  "Vamos contar quantos valores pares, ímpares, positivos e negativos voce digitou\n\n"
  "(exceto, obviamente, N).\n\n Voce consegue :3\n\n");

  int N,x;
  printf("Digite o valor de N, seguido dos N numeros\n"
  "(apertando ENTER entre as entradas): N=");
  scanf("%d",&N);

  int i,numerodepares=0,numerodeimpares=0,numerodepositivos=0,numerodenegativos=0;
  for (i=1;i<=N;i++) {
    scanf("%d",&x);
    if (x%2==0){
      numerodepares++;
    }
    else {
      numerodeimpares++;
    }

    if (x>0){
      numerodepositivos++;
    }
    else if (x<0){
      numerodenegativos++;
    }
  }

  printf("\nVoce digitou\n");
  printf("%d valor(es) par(es)\n",numerodepares);
  printf("%d valor(es) impar(es)\n",numerodeimpares);
  printf("%d valor(es) positivo(s)\n",numerodepositivos);
  printf("%d valor(es) negativo(s)\n",numerodenegativos);

  return 0;
}
//Se pões float num x, também dá bug
