#include <stdio.h>

int main() {
  printf("Este programa calcula o tempo entre dois horarios inteiros dados\n\n"
  "(início e fim de um jogo), sabendo que os podem estar\n"
  "em dias diferentes, com uma diferença de no maximo 24 horas\n\n");

  int inicio=25, fim=25;
  while (inicio>23 || fim>23 || inicio<0 || fim<0) {
    printf("Digite os dois horarios (como numeros inteiros entre 0 e 23): ");

    scanf("%d %d", &inicio, &fim);

    if (inicio>23 || fim>23 || inicio<0 || fim<0) {
      printf("HORARIOS INVALIDOS. Tente novamente.\n\n");
    }
  }

  if (fim==inicio+1) {
    printf("O JOGO DUROU 1 HORA.\n");
  }
  else if (fim>inicio) {
    printf("O JOGO DUROU %d HORAS.\n", fim-inicio);
  }
  else {
    printf("O JOGO DUROU %d HORAS.\n", fim-inicio+24);
  }

  return 0;
}
//Se põe float no lugar dos horários ele também dá um bug.
