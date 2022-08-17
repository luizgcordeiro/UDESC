#include <stdio.h>

//copia e adapta a anterior

int main() {
  printf("\n\nDigite um inteiro N. Após isso, digite N triplas de números (float),\n"
  "com ate uma casa decimal apos a virgula. Apos cada uma dessas triplas ser\n"
  "digitada, voce obtera a media ponderadas da tripla, com o primeiro tendo peso 2,\n"
  "o segundo tendo peso 3 e o terceiro tendo peso 5 (arredondada para uma casa\n"
  "apos a virgula).\n\n");

  int N;
  float x,y,z;
  printf("Digite o valor de N, seguido das N triplas de numeros\n"
  "(apertando ENTER entre as entradas): N=");
  scanf("%d",&N);

  int i;
  for (i=1;i<=N;i++) {
    scanf("%f %f %f",&x,&y,&z);
    printf("A media ponderada eh %.1f\n",(2*x+3*y+5*z)/10);
  }

  return 0;
}
