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
void merge_sort(int*x,int*y, int n);/*Merge sort*/
void merge_sort_merge(int*x, int m, int*y, int n, int*z); /*Função complementar pra merge sort*/
int pertence(int x,int*v,int n);/*Função que verifica se um inteiro x
pertence a um conjunto (string) v de tamanho n*/
void uniao(int *x,int m, int *y, int n,int* z, int k);//Uniao
void interseccao (int *x,int m, int *y, int n,int* z, int k);//Interseccao

int main() {

  printf(
  "==================================================\n"
  "   _      _____   _____  ___   ___   ___  __        \n"
  "  | |    |  __ \\ / ____|/ _ \\ / _ \\ / _ \\/_ |   \n"
  "  | |    | |__) | |  __| | | | | | | | | || |       \n"
  "  | |    |  ___/| | |_ | | | | | | | | | || |       \n"
  "  | |____| |    | |__| | |_| | |_| | |_| || |       \n"
  "  |______|_|     \\_____|\\___/_\\___/ \\___/ |_|   \n"
  "   _             _           _ _             __     \n"
  "  | |           | |         | | |           /_ |    \n"
  "  | |_ _ __ __ _| |__   __ _| | |__   ___    | |    \n"
  "  | __| '__/ _` | '_ \\ / _` | | '_ \\ / _ \\   | | \n"
  "  | |_| | | (_| | |_) | (_| | | | | | (_) |  | |    \n"
  "   \\__|_|  \\__,_|_.__/ \\__,_|_|_| |_|\\___/   |_|\n"
  "                                                \n"
  "==================================================\n"
  "Aluno: Luiz Gustavo Cordeiro\n"
  "Semestre: 2022-1\n"
  "Professor: Rui Tramontin"
  "\n"
  "==================================================\n");

  printf(
    "Este programa guarda ate %d conjuntos com ate %d elementos\n"
    "inteiros e nao-nulos.\n",
    M,N
  );

  int matriz[M][N]={0};
  int contador=0;//Numero de conjuntos ja criados
  int opcao=0;
  int indice;//indice do conjunto a se trabalhar
  int indice1,indice2;
  int tamanhos[M]={0};//Tamanho dos conjuntos ja criados.
  int x;//variavel temporaria

  while (1) {
    printf("==================================================\n");
    printf("\n\n\n");
    printf("==================================================\n");
    if (opcao==1) {
      if (contador==M) {
        printf(
          "Voce ja chegou no numero maximo de conjuntos a serem "
          "criados. :'(\n");
      }
      else {
        printf("Voce criou um conjunto vazio no indice %d.\n",contador);
        contador+=1;
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
            scanf(" %d",&x);

            if (x!=0) {
              if (pertence(x,*matriz+N*indice,tamanhos[indice])) {
                printf("O numero %d ja pertence ao conjunto de indice %d!\n",x,indice);
              }
              else {
                matriz[indice][tamanhos[indice]]=x;
                tamanhos[indice]+=1;
                printf("Voce adicionou o numero %d ao conjunto de indice %d.\n",x,indice);
                    /*Coisinhas pra teste
                    imprimir_matriz(*matriz,M,N);
                    */
              }
            }
            else {
              break;
            }
          }
          printf("\nO conjunto de indice %d agora tem %d elementos.\n",indice,tamanhos[indice]);
          if (tamanhos[indice]==N) {
            printf("Voce nao pode mais inserir dados neste conjunto!\n");
          }
        }
      }
    }
    ///////////////////////////////////
    else if (opcao==3) {//Remover um conjunto
      if (contador==0) {
        printf("Voce nao tem conjuntos para remover! >:'(\n");
      }
      else {
        printf("Qual o indice do conjunto que voce quer remover?\n");
        printf("Digite um numero entre 0 e %d: ",contador-1);
        scanf(" %d",&indice);

        if (indice>contador-1 || indice<0) {
          printf("Indice invalido! Tente novamente.\n");
        }
        else {
          int i,j;
          for (i=indice+1;i<contador;i++) {
            for (j=0;j<N;j++) {
              //Substitui linhas
              matriz[i-1][j]=matriz[i][j];
            }
            tamanhos[i-1]=tamanhos[i];
          }
          for (j=0;j<N;j++) {
            matriz[contador-1][j]=0;
          }
          tamanhos[contador-1]=0;
          contador-=1;
          printf("Voce removeu o conjunto de indice %d.\n",indice);
        }
      }
    }
    ///////////////////////////////////
    else if (opcao==4) {
      if (contador==0) {
        printf("Voce nao tem conjuntos para unir! :p\n");
      }
      else if (contador==1) {
        printf("Voce so tem um conjunto para unir consigo mesmo, o que e\n"
      "inutil. Tente outra coisa.\n");
      }
      else if (contador==M) {
        printf("Voce nao tem espaço para criar uma uniao! >.<\n");
      }
      else {
        printf("Qual o indice do primeiro conjunto que voce quer "
          "por na uniao?\n"
          );
        printf("Digite um numero entre 0 e %d: ",contador-1);
        scanf(" %d",&indice1);

        printf("Qual o indice do segundo conjunto que voce quer "
          "por na uniao?\n"
          );
        printf("Digite um numero entre 0 e %d: ",contador-1);
        scanf(" %d",&indice2);

        if (indice1>contador-1 || indice1<0 || indice1>contador-2 || indice2<0) {
          printf("Algum indice foi invalido! Tente novamente.\n");
        }
        else {
          uniao(*matriz+N*indice1,tamanhos[indice1],*matriz+N*indice2,tamanhos[indice2],*matriz+N*contador,N);
          printf("A uniao dos conjuntos de indice %d e %d foi guardada no\n"
            "conjunto de indice %d",indice1,indice2,contador);
          //Precisa verificar qual o tamanho do conjunto criado
          int j=0;
          while (matriz[contador][j]!=0 & j<N) {
            tamanhos[contador]+=1;
            j++;
          }
          contador+=1;
        }
      }
    }
    ///////////////////////////////////
    else if (opcao==5) {
      if (contador==0) {
        printf("Voce nao tem conjuntos para intersectar! :o\n");
      }
      else if (contador==1) {
        printf("Voce so tem um conjunto para intersectar consigo mesmo, o que e\n"
          "inutil. Tente outra coisa.\n");
      }
      else if (contador==M) {
        printf("Voce nao tem espaço para criar uma interseccao! >:o\n");
      }
      else {
        printf("Qual o indice do primeiro conjunto que voce quer "
          "por na interseccao?\n"
          );
        printf("Digite um numero entre 0 e %d: ",contador-1);
        scanf(" %d",&indice1);

        printf("Qual o indice do segundo conjunto que voce quer "
          "por na interseccao?\n"
          );
        printf("Digite um numero entre 0 e %d: ",contador-1);
        scanf(" %d",&indice2);

        if (indice1>contador-1 || indice1<0 || indice1>contador-2 || indice2<0) {
          printf("Algum indice foi invalido! Tente novamente.\n");
        }
        else {
          interseccao(*matriz+N*indice1,tamanhos[indice1],*matriz+N*indice2,tamanhos[indice2],*matriz+N*contador,N);
          printf("A interseccao dos conjuntos de indice %d e %d foi guardada no\n"
            "conjunto de indice %d",indice1,indice2,contador);
          //Precisa verificar qual o tamanho do conjunto criado
          int j=0;
          while (matriz[contador][j]!=0 & j<N) {
            tamanhos[contador]+=1;
            j++;
          }
          contador+=1;
        }
      }
    }
    ///////////////////////////////////
    else if (opcao==6) {

      if (contador==0) {
        printf("Voce nao tem conjuntos para intersectar! o.O\n");
      }
        else {
        printf("Qual o indice do conjunto que voce quer exibir?\n");
        printf("Digite um numero entre 0 e %d: ",contador-1);
        scanf(" %d",&indice);

        if (indice>contador-1 || indice<0) {
          printf("Indice invalido! Tente novamente.\n");
          indice=-1;
        }
        else {
          printf("O conjunto de indice %d e\n",indice);
          printf("{");
          imprimir_matriz(*matriz+(indice*N),1,tamanhos[indice]);
          printf("}\n");
        }
      }
    }
    ///////////////////////////////////
    else if (opcao==7) {
      if (contador==0) {
        printf("Voce ainda nao criou nenhum conjunto...\n"
          "Nao ha nada para mostrar.\n"
        );
      }
      else {
        printf("Os conjuntos criados sao:\n");
        int i;
        for (i=0;i<contador;i++) {
          printf("  Indice %d: {",i);
          imprimir_matriz(*matriz+i*N,1,tamanhos[i]);
          printf("}\n");
        }
      }
    }
    ///////////////////////////////////
    else if (opcao==8) {
      if (contador==0) {
        printf("Voce ainda nao criou nenhum conjunto...\n"
          "Nao ha onde procurar nenhum valor! ><\n"
        );
      }
      else {
        printf("Qual numero voce quer buscar nos conjuntos?\n");
        printf("Digite um numero inteiro nao-nulo: ");
        scanf(" %d",&x);
        if (x==0) {
          printf("0 nao é nao-nulo, oooooo...\n");
        }
        else {
          int i,j=0, contem[M]={0};
          for (i=0;i<contador;i++) {
            if (pertence(x,*matriz+N*i,tamanhos[i])) {
              contem[j]=i;
              j++;
            }
          }

          //Neste ponto, "contem" é um vetor que contém, em ordem,
          //os indices dos conjuntos que contêm x,
          //e j é o tamanho de "contem".

          if (j==0) {
            printf("Nenhum conjunto contem %d.\n",x);
          }
          else if (j==1) {
            printf("Somente o conjunto de indice %d contem %d.\n",contem[0],x);
          }
          else {
            printf("Os conjuntos de indices ");
            for (i=0;i<j-2;i++) {
              printf("%d, ",contem[i]);
            }
            printf("%d e %d contem %d.\n",contem[j-2],contem[j-1],x);
          }
        }
      }
    }
    ///////////////////////////////////
    else if (opcao==9) {
      printf("Au revoir :'(\n");
      break;
    }
    else {
      printf(
        "Atualmente, voce tem %d conjuntos criados.\n"
        "Escolha uma das seguintes opcoes:\n"
        "  1. Criar um novo conjunto vazio.\n"
        "  2. Inserir dados em um conjunto.\n"
        "  3. Remover um conjunto.\n"
        "  4. Fazer a uniao de dois conjuntos.\n"
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

    /*Coisinhas pra teste
    printf("contador=%d\n",contador);
    printf("matriz=\n");
    imprimir_matriz(*matriz,M,N);
    printf("\ntamanhos=[");
    imprimir_matriz(tamanhos,1,M);
    printf("]\n");
    */

    printf(
      "Digite um numero de 1 a 9 para fazer a acao correspondente,\n"
      "ou qualquer outro numero para rever as opcoes disponiveis: "
    );

    scanf(" %d",&opcao);
  }


  return 0;
}

void imprimir_matriz(int * a, int m, int n) {
  if (n==0) {
    return;
  }

  int i,j;

  int maiorelemento=0;
  for (i=0;i<m;i++) {
    for (j=0;j<n;j++) {
      maiorelemento=maximo(maiorelemento,abs(a[m*i+j]));
    }
  }

  int k=numero_de_digitos(maiorelemento);//Tem espaço para sinal.
  for (i=0;i<m;i++) {
    for (j=0;j<n-1;j++) {
      printf("%*d , ",k,a[n*i+j]);//Antes do ultimo poe uma virgula
    }
    printf("%*d",k,a[n*i+j]);//No ultimo nao poe nada
    if (i<m-1) {
      printf("\n");
    }
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

void merge_sort(int*x,int*y, int n) {
  /*Merge sort from x, stored at y, both with length n*/
  if (n==1) {
    y[0]=x[0];
    return;
  }
  int middle=n/2;
  merge_sort_merge(x,middle,x+middle,n-middle,y);
  return;
}

void merge_sort_merge(int*x, int m, int*y, int n, int*z) {
  /*Ordered merge of two ordered lists x and y of length m and n into a list z*/
  int i=0,j=0,cont=0;
  while (i<m && j<n) {
    if (x[i]<=y[j]) {
      z[i+j]=x[i];
      i+=1;
    }
    else {
      z[i+j]=y[j];
      j+=1;
    }
    /*Nesse ponto, z já tem armazenados todos os valores de x ou de y,
    e os que sobrarem no outro são maiores e ordenados*/
  }

  /*Basta pôr os valores que restam DE x e DE y em z*/
  for (;i<m;i++) {
    z[i+j]=x[i];
  }
  for (;j<n;j++) {
    z[i+j]=y[j];
  }
  return;
}

int pertence(int x,int*v,int n) {
  if (n==0) {
    return 0;
  }

  if (x==v[0]) {
    return 1;
  }

  //recursão
  return pertence(x,v+1,n-1);
}

void uniao(int *x,int m, int *y, int n,int* z, int k) {
  /*Faz a uniao de dois conjuntos x e y, com m e n elementos;
  guarda os "primeiros" k elementos em z.
  Assume-se pelo menos que k>=m, e que x nao tem
  elementos repetidos. Da uma mensagem de
  erro caso nao haja espaço suficiente em z.*/
  int i;
  //Faz uma copia de x em z
  for (i=0;i<m;i++) {
    z[i]=x[i];
  }

  //Neste ponto, i=m
  int j;
  //Corre em y
  for (j=0;j<n && i<k;j++) {
    if (!(pertence(y[j],z,i))) {//Se y[j] não pertence a x
      z[i]=y[j];
      i++;
    }
    else {//Se y[j] pertence a x
    }
  }

  /*Agora, a gente verifica se algum dos elementos que sobraram em y
  pertence ou nao a z.
  Note que i é o tamanho de z...*/
  for (;j<n;j++) {
    if (!(pertence(y[j],z,i))) {
      printf("AVISO: NAO HA ESPACO SUFICIENTE NA UNIAO!\n");
      j=n;
    }
  }
}

void interseccao (int *x,int m, int *y, int n,int* z, int k) {
  int i,j=0;
  for (i=0;i<m;i++) {
    if (pertence(x[i],y,n)) {
      z[j]=x[i];
      j++;
    }
  }
}
