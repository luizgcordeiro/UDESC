#include <stdio.h>

int maxof2int(int a, int b);//funcao que toma o maximo de 2 numeros
int minof2int(int a, int b);//funcao que toma o maximo de 2 numeros
/*Vamos transformar o código do exercício anterior em uma função.*/
int somadosimpares(int x, int y);//função que calcula a soma dos ímpares entre x e y

int main() {
  printf("\n\nEste programa calcula a soma dos valores ímpares entre dois números\n"
  "para vários pares de números (\"casos-teste\").\n\n");

  printf("Quantos casos-teste você quer fazer? ");

  int N;
  scanf("%d",&N);

  printf("\nAgora, escreva %d pares de números inteiros (separe as entradas\n"
  "de cada par por um espaço, e os pares por linhas.)\n\n",N);

  int i;
  for (i=1;i<=N;i++) {
    int x,y;
    scanf("%d %d",&x,&y);

    printf("A soma dos numeros impares entre %d e %d eh %d\n\n",x,y,somadosimpares(x,y));
  }

  return 0;
}

int maxof2int(int a, int b) {
  if (a>b) {
    return a;
  }
  return b;
}

int minof2int(int a, int b) {
  if (a>b) {
    return b;
  }
  return a;
}

int somadosimpares(int x, int y) {
  /*Acha o primeiro ímpar após o menor dentre x e y.*/
  int m=maxof2int(x,y);
  int i=minof2int(x,y)+1;
  if (i%2==0) {
    i++;
  }
  int soma=0;
  /*Fazemos o loop usual, com passo 2. Note que i já está inicializado*/
  for (;i<m;i+=2) {
    soma+=i;
  }

  return soma;
}
