#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compara(float a[], float b[], int n);//ex1
void fibonacci(int v[], int n);//ex2
int soma_primos(int v[], int n);//ex3
void busca_todos(int v[], int n, int chave, int indices[]);//ex4
int busca_seq_rec(int v[], int n, int chave);//ex5
int e_primo(int p);//Dependência do exercício 3.

int main() {

  return 0;
}

/*Exercício 1*/
int compara(float a[], float b[], int n) {
  /*Recursion for the win*/
  if (n==0) {
    return 1;
  }
  if (a[0]==b[0]) {
    return 0;
  }
  return compara(a+1,b+a,n-1);
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
    if e_primo(v[i]) {
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

  return
}

/*Exercício 5*/
int busca_seq_rec(int v[], int n, int chave) {
  if n<0 {
    return -1;//Parâmetro inválido, etc.
  }
  /*
  Seria mais fácil fazer uma recursão inversa:

    if (v[n]==chave) {
      return n;
    }
    return busca_seq_rec(v,n-1,chave)

  que retornaria o MAIOR índice que bate na chave. Mas a busca
  sequencia vai em sequência, então é mais chato :(
  */
  if (v[0]==chave) {
    return 0;
  }
  return busca_seq_rec(v+1,n-1,chave)+1;
}
