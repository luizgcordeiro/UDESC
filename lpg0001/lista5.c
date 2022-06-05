#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define PI 3.1415926535897932384626433832

void inc_dec (int *a, int *b);//Exercicio 1
void troca_valor(float *x, float *y);//Exercício 2
void calcula_circulo(float raio, float *pPerimetro, float *pArea);//Exercício 3
void cacula_hora(int totalMinutos, int *ph, int *pm);//Exercício 4

int main() {
  printf("LISTA 5\n");
  printf("\n");
  printf("=============\n");


  int num_ex=1;
  while (num_ex!=0) {

    printf("Digite o numero do exercicio que voce quer testar (1 a 7)\n"
      "ou 0 para sair: ");
    scanf("%d",&num_ex);

    if (num_ex==1) {
      int a,b;
      printf("Digite um valor para a: ");
      scanf("%d",&a);

      printf("Digite um valor para b: ");
      scanf("%d",&b);

      inc_dec(&a,&b);

      printf("Os novos valores sao a=%d e b=%d.\n",a,b);
    }
    else if (num_ex==2) {
      float x,y;
      printf("Digite um valor (float) para x: ");
      scanf("%f",&x);
      printf("Digite um valor (float) para y: ");
      scanf("%f",&y);

      char trocar='S';

      while (trocar=='S') {

        printf("Os valores atuais sao x=%.4f e y=%.4f.\n",x,y);

        //Limpa stdin
        int cc;
        while ( (cc = getchar()) != '\n' && cc != EOF );
        //

        printf("Você quer trocar os valores de posicao (S/N)? ");

        scanf("%c",&trocar);
        if (trocar=='S') {
          troca_valor(&x,&y);
        }

      }
    }
    else if (num_ex==3) {
      float raio,pPerimetro,pArea;
      printf("Digite um valor (float, posivito) para o raio de um circulo: ");
      scanf("%f",&raio);
      while (raio<0) {
        printf("Valor invalido (negativo)!!!\n");
        printf("Digite um valor (float, posivito) para o raio de um circulo: ");
        scanf("%f",&raio);
      }


      calcula_circulo(raio,&pPerimetro,&pArea);

      printf("O circulo tem:\n");
      printf("  Raio=%.4f\n",raio);
      printf("  Perimetro=%.4f\n",pPerimetro);
      printf("  Área=%.4f\n",pArea);
    }
    else if (num_ex==4) {
      int totalMinutos,ph,pm;

      printf("Quantos minutos ja se passaram desde a meia noite? ");
      scanf("%d",&totalMinutos);

      while (totalMinutos<0) {
        printf("Valor invalido (negativo)!!!\n");
        printf("Quantos minutos ja se passaram desde a meia noite? ");
        scanf("%d",&totalMinutos);
      }

      cacula_hora(totalMinutos,&ph,&pm);

      printf("\nAgora");
      if (ph==0) {
        printf(" e meia-noite");
      }
      else if (ph==12) {
        printf(" e meio-dia");
      }
      else if (ph%12==1) {
        printf(" e uma");
      }
      else {
        printf(" sao %d",ph%12);
      }

      if (pm==30) {
        printf(" e meia");
      }
      else if (pm!=00) {
        printf(" e %d",pm);
      }

      if (ph>12) {
        printf(" da tarde");
      }
      else if (!(ph%12==0)) {
        printf(" da manha");
      }

      printf(".\n\n");
    }
    else if (num_ex==5) {

    }
    else if (num_ex==6) {

    }
    else if (num_ex==7) {

    }
    printf("=============\n");
  }
  return 0;
}

/*
  1)Faça uma função que recebe dois números, a e b. A função deve incrementar a
  e decrementar b.
*/

void inc_dec (int *a, int *b) {
  (*a)++;
  (*b)--;
  return;
}

/*
  2) Escreva uma função que troca os valores entre duas variáveis do tipo float.
  Faça um programa que leia duas variáveis e mostre seus valores na tela.
  Em seguida, troque os valores (usando a função) e mostre novamente os valores.
*/

void troca_valor(float *x, float *y) {
  (*x)+=(*y);
  (*y)=(*x)-(*y);
  (*x)-=(*y);
  return;
}


/*
  3) Faça uma função que calcula o perímetro e a área de um círculo, dado o
  raio.
*/

void calcula_circulo(float raio, float *pPerimetro, float *pArea) {
  *pPerimetro=2*PI*raio;
  *pArea=PI*raio*raio;
}

/*
  4) Faça uma função que receba um parâmetro (por valor) com o total de minutos
  passados ao longo do dia e receba também dois parâmetros (referência) no qual
  deve preencher com o valor da hora e do minuto corrente. Faça um programa que
  leia do teclado quantos minutos se passaram desde meia-noite e imprima a hora
  corrente (use a sua função).
*/

void cacula_hora(int totalMinutos, int *ph, int *pm) {
  (*ph)=totalMinutos/60;
  (*pm)=totalMinutos%60;
  return;
}

/*
  5) Escreva uma função que recebe um vetor e sua capacidade como parâmetros e
  precisa “retornar” o maior e o menor valores do vetor.
*/

void max_min(int vet[], int tam, int *pMin, int *pMax){
  return;
}
