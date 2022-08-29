#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M 30
#define N 4

int compara(float a[], float b[], int n);//ex1
void fibonacci(int v[], int n);//ex2
int soma_primos(int v[], int n);//ex3
void busca_todos(int v[], int n, int chave, int indices[]);//ex4
int busca_seq_rec(int v[], int n, int chave);//ex5
int e_primo(int p);//Dependência do exercício 3.

int main() {
  srand(time(0));

  int v[M],indices[M],i;
  float a[M],b[M];

  for (i=0;i<M;i++) {
    v[i]=rand()%N;
    a[i]=(float)(rand()%N);
    b[i]=(float)(rand()%N);
  }

  int testar;
  printf("Qual exercicio voce quer testar? ");
  scanf("%d",&testar);

  if (testar==1) {
    printf("==========\nTeste para o exercício 1.\n==========\n");
    printf("\n");
    printf("Considere os vetores\n");
    printf("a=[");
    for (i=0;i<M-1;i++) {
      printf("%.0f,",a[i]);
    }
    printf("%.0f]\n",a[M-1]);
    printf("e\n");
    printf("b=[");
    for (i=0;i<M-1;i++) {
      printf("%.0f,",b[i]);
    }
    printf("%.0f]\n",b[M-1]);

    int n,m;


    char tentar_de_novo='S';
    while (tentar_de_novo=='S') {
      printf("Escolha números n e m. Vamos verificar se a[i]==b[i] para\n"
      "todo i=n,n+1,...m.\n");

      printf("n=");
      scanf("%d",&n);
      printf("m=");
      scanf("%d",&m);
      printf("\n");

      if (compara(a+n,b+n,m-n+1)) {
        printf("Os vetores coincidem nessa parte!\n");
      }
      else {
        printf("Os vetores não coincidem nessa parte.\n");
      }

      printf("\nVocê quer tentar de novo (S/N)? ");
      scanf("%c",&tentar_de_novo);
      while (tentar_de_novo=='\n') {
        scanf("%c",&tentar_de_novo);
      }
      printf("\n");
    }
  }

  if (testar==2) {
    printf("\n==========\nTeste para o exercício 2.\n==========\n");
    printf("Considere o vetor\n");
    printf("v=[");
    for (i=0;i<M-1;i++) {
      printf("%d,",v[i]);
    }
    printf("%d]\n",v[M-1]);
    printf("Quantas entradas de v você quer mudar, para\n"
    "virar a sequência de Fibonaci? ");

    int n;
    scanf("%d",&n);

    if (n>=1) {
      fibonacci(v,n);
      printf("Agora o vetor v eh\n");
      printf("v=[");
      for (i=0;i<M-1;i++) {
        printf("%d,",v[i]);
      }
      printf("%d]\n",v[M-1]);
    }
  }

  if (testar==3) {
    printf("\n==========\nTeste para o exercício 3.\n==========\n");
    printf("Escolha o tamanho do vetor que voce quer criar (<=%d): ",M);
    int n;
    scanf("%d",&n);
    int i;
    printf("Escreva as entradas do vetor:\n");
    for (i=0;i<M;i++) {
      scanf("%d",&v[i]);
    }
    printf("A soma das entradas primas que voce escreveu e %d.",soma_primos(v,n));
  }

  if (testar==4) {
    printf("\n==========\nTeste para o exercício 4.\n==========\n");
    printf("Considere o vetor\n");
    printf("v=[");
    for (i=0;i<M-1;i++) {
      printf("%d,",v[i]);
    }
    printf("%d]\n",v[M-1]);
    printf("Escolha um numero inteiro: ");
    int chave;
    scanf("%d",&chave);
    printf("O numero %d aparece nas posicoes\n",chave);
    int pos_indices[M];
    busca_todos(v,M,chave,pos_indices);
    int i;
    for (i=0;(i<M) & (pos_indices[i]!=-1);i++) {
      printf("%d, ",pos_indices[i]);
    }
  }

  if (testar==5) {
    printf("\n==========\nTeste para o exercício 5.\n==========\n");
    printf("Considere o vetor\n");
    printf("v=[");
    for (i=0;i<M-1;i++) {
      printf("%d,",v[i]);
    }
    printf("%d]\n",v[M-1]);
    printf("Qual entrada de v voce quer achar? ");
    int chave;
    scanf("%d",&chave);
    int primeira_posicao=busca_seq_rec(v,M,chave);
    if (primeira_posicao!=(-1)) {
      printf("A entrada %d aparece pela última vez na posicao %d.",chave,primeira_posicao);
    }
    else {
      printf("A entrada %d nao aparece no vetor.");
    }

  }

  printf("\n");
  return 0;
}

/*Exercício 1*/
int compara(float a[], float b[], int n) {
  /*Recursion for the win*/
  if (n==0) {
    return 1;
  }
  if (a[0]!=b[0]) {
    return 0;
  }
  return compara(a+1,b+1,n-1);
}

/*Exercício 2*/
void fibonacci(int v[], int n) {
  if (n>=1) {
    v[0]=1;
    if (n>=2) {
      v[1]=1;
      int i;
      for (i=2;i<n;i++) {
        v[i]=v[i-1]+v[i-2];
      }
      return;
    }
    return;
  }
  return;
}

/*Exercício 3*/
/*Copia e cola abaixo*/
/*Neste caso, como é só uma função, é mais fácil copias e colar do que
importar o arquivo (que no meu computador se encontra em uma subpasta de uma
"super"pasta.)*/
int e_primo(int p) {
  if (p<0) {//Tira o caso negativo
    return e_primo(-p);
  }
  //Considera p=0 separadamente
  if (p==0) {
    return 0;//0 não é primo
  }
  //Caso contrário, temos que ver se algum número entre 2 sqrt(p) divide p
  int k;
  for (k=2;k*k<=p;k++) {
    if (p%k==0) {
      return 0;
    }
  }
  return 1;
}

/*Exerćicio 3 de verdade*/
int soma_primos(int v[], int n) {
  int i,soma=0;
  for (i=0;i<n;i++) {
    if (e_primo(v[i])) {
      soma+=v[i];
    }
  }
  return soma;
}

/*Exercício 4*/
void busca_todos(int v[], int n, int chave, int indices[]) {
  int i,ind=0;//"ind" é a entrada a ser preenchido em indices[]
  for (i=0;i<n;i++) {
    if (v[i]==chave) {
      indices[ind]=i;
      ind++;
    }
  }

  for (i=ind;i<n;i++) {
    indices[i]=-1;
  }

  return;
}

/*Exercício 5*/
int busca_seq_rec(int v[], int n, int chave) {
  /*
  Eu imagino que se queria fazer uma busca sequencial da
  esquerda para a direita:

    if (v[0]==chave) {
      return 0;
    }
    return busca_seq_rec(v+1,n-1,chave)+1;

  Mas nesse caso eu não sei como dar -1 caso a chave não
  aparecesse no vetor.

  Por outro lado, isso fica trivial fazendo a busca da direita pra
  esquerda ;)

  Também é recursivo, só que ao contrário :3
  */

  if (n<=0) {
    return -1;
  }

  if (v[n-1]==chave) {
    return n-1;
  }

  return busca_seq_rec(v,n-1,chave);
}
