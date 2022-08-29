#include <stdio.h>

void movimento_hanoi (int k, char inic, char fim);
char outro(char x, char y);

int main() {
  int n;
  printf("Quantos discos você quer mover? ");
  scanf("%d",&n);
  printf("\n");
  movimento_hanoi(n,'A','C');
  return 0;
}

void movimento_hanoi (int k, char inic, char fim) {
  /*Movimentar k discos de n para m*/
  if (k==1) {
    printf("Movimente o disco 1 de %c para %c\n",inic,fim);
  }
  else {
    movimento_hanoi(k-1, inic, outro(inic, fim));
    printf("Movimente o disco %d de %c para %c\n",k,inic,fim);
    movimento_hanoi(k-1,outro(inic,fim),fim);
  }
}

char outro(char x, char y) {
  if (x=='A' && y=='B') {
    return 'C';
  } else if (x=='A' && y=='C') {
    return 'B';
  } else if (x=='B' && y=='A') {
    return 'C';
  } else if (x=='B' && y=='C') {
    return 'A';
  } else if (x=='C' && y=='A') {
    return 'B';
  } else if (x=='C' && y=='B') {
    return 'A';
  }
}
