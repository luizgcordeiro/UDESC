#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10//Tamanho máximo dos conjuntos
#define M 8//Numero máximo de conjuntos

int maximo(int m, int n);//Função que calcula o máximo de m,n
int numero_de_digitos(int m);/*Função que calcula o número de
dígitos de m, deixando um espaço para o sinal (sempre)*/
int pot(int m,int k);/*Função que cacula m^k*/
void imprimir_matriz(int * a,int m, int n);/*Função que imprime
Uma matriz guardada no ponteiro a, de tamanho m por n*/

int main() {

  printf(
  " =================================================\n"
  "   _      _____   _____  ___   ___   ___  __    \n"
  "  | |    |  __ \\ / ____|/ _ \\ / _ \\ / _ \\/_ |   \n"
  "  | |    | |__) | |  __| | | | | | | | | || |   \n"
  "  | |    |  ___/| | |_ | | | | | | | | | || |   \n"
  "  | |____| |    | |__| | |_| | |_| | |_| || |   \n"
  "  |______|_|     \\_____|\\___/_\\___/ \\___/ |_| \n"
  "   _             _           _ _             __ \n"
  "  | |           | |         | | |           /_ |\n"
  "  | |_ _ __ __ _| |__   __ _| | |__   ___    | |\n"
  "  | __| '__/ _` | '_ \\ / _` | | '_ \\ / _ \\   | |\n"
  "  | |_| | | (_| | |_) | (_| | | | | | (_) |  | |\n"
  "   \\__|_|  \\__,_|_.__/ \\__,_|_|_| |_|\\___/   |_|\n"
  "                                                \n"
  "====================================================\n"
  "Aluno: Luiz Gustavo Cordeiro\n"
  "Semestre: 2022-1\n"
  "Professor: Rui Tramontin"
  "\n"
  "================================================\n");
  printf(
    "Este programa guarda ate %d conjuntos com ate %d elementos\n"
    "inteiros e nao-nulos.\n",
    M,N
  );

  int matriz[M][N]={0};
  int contador=0;//Numero de conjuntos ja criados
  int opcao=0;
  int indice;//indice do conjunto a se trabalhar
  int tamanhos[M]={0};//Tamanho dos conjuntos ja criados.

  while (1) {
    printf("==================================================\n");
    if (opcao==1) {
      if (contador==M) {
        printf(
          "Voce ja chegou no numero maximo de conjuntos a serem "
          "criados. :'(\n");
      }
      else {
        contador+=1;
        printf("Voce criou um conjunto vazio no indice %d.\n",contador);
      }
    }
    ///////////////////////////////////
    else if (opcao==2) {
      if (contador==0) {
        printf("Voce nao tem conjuntos para inserir dados! >:(\n");
      }
      else {
        printf(
          "Qual o indice do conjunto no qual voce quer inserir dados?\n"
          "Digite um numero entre 0 e %d: ",
          contador-1
        );
        scanf(" %d",&indice);

        if (indice>contador-1 || indice<0) {
          printf("Indice invalido! Tente novamente.\n");
          indice=-1;
        }
        else if (tamanhos[indice]==N) {
          printf("Voce nao pode mais inserir dados neste conjunto!\n");
        }
        else {
          while (tamanhos[indice]<N) {
            printf(
              "\nEscreva o(s) valor(es) que voce quer inserir no conjunto\n"
              "de indice %d. Ponha um zero para terminar: ",
              indice);
            scanf(" %d",&matriz[indice][tamanhos[indice]+1]);
            if (matriz[indice][tamanhos[indice]+1]!=0) {
              /*Verifica se ja pertence ao conjunto*/
              /*Se nao for o caso*/
              tamanhos[indice]+=1;
              /*Mas se for o caso, avisa e não faz nada*/
            }
            else {
              break;
            }
          }
          printf("\nO conjunto de indice %d agora tem %d elementos.\n",indice,tamanhos[indice]);
        }
      }
    }
    ///////////////////////////////////
    else if (opcao==3) {

    }
    ///////////////////////////////////
    else if (opcao==4) {

    }
    ///////////////////////////////////
    else if (opcao==5) {

    }
    ///////////////////////////////////
    else if (opcao==6) {

    }
    ///////////////////////////////////
    else if (opcao==7) {

    }
    ///////////////////////////////////
    else if (opcao==8) {

    }
    ///////////////////////////////////
    else if (opcao==9) {
      printf("Au revoir.");
      break;
    }
    else {
      printf(
        "Atualmente, voce tem %d conjuntos criados.\n"
        "Escolha uma das seguintes opcoes:\n"
        "  1. Criar um novo conjunto vazio.\n"
        "  2. Inserir dados em um conjunto.\n"
        "  3. Remover um conjunto.\n"
        "  4. Fazer a unao de dois conjuntos.\n"
        "  5. Fazer a interseccao de dois conjuntos.\n"
        "  6. Mostrar um conjunto.\n"
        "  7. Mostrar todos os conjuntos.\n"
        "  8. Buscar por um valor nos conjuntos.\n"
        "  9. Sair do programa\n"
        "Se voce escolher uma opcao diferente das acima, as opcoes\n"
        "serao reexibidas.\n",
        contador);
    }
    printf("==================================================\n");

    printf(
      "Digite um numero de 1 a 9 para fazer a acao correspondente,\n"
      "ou qualquer outro numero para rever as opcoes disponiveis: "
    );

    scanf(" %d",&opcao);
  }

  imprimir_matriz(*matriz,M,N);

  return 0;
}

void imprimir_matriz(int * a, int m, int n) {
  int i,j;

  int maiorelemento=0;
  for (i=0;i<m;i++) {
    for (j=0;j<n;j++) {
      maiorelemento=maximo(maiorelemento,abs(a[m*i+j]));
    }
  }

  int k=numero_de_digitos(maiorelemento);//Tem espaço para sinal.
  for (i=0;i<M;i++) {
    for (j=0;j<N;j++) {
      printf("%*d ",k,a[m*i+j]);
    }
    printf("\n");
  }
}

int maximo(int m, int n) {
  if (m>n) {
    return m;
  }
  return n;
}

int pot(int m,int k) {
  if (k==0) {
    return 1;
  }
  return m*pot(m,k-1);
}

int numero_de_digitos(int m) {
  int i=0;
  while (pot(10,i)<m) {
    /*Se sai em i=1, tem 1 dígito; se sai em i=2, tem 2...*/
    i++;
  }
  return i+1;//Tem espaço para o sinal;
}
