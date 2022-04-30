#include <stdio.h>

int minoftwo(int a, int b);
int menorvalor(int n, int a[]);
int menorentrada(int n, int a[]);
int* selection_sort(int n, int a[]);

int main () {
  int i, v[10]={5,3,5,6,7,1,2,8,4,9};
  int* x=selection_sort(10,v);

  for (i=0;i<=9;i++) {
    printf("%d",x[i]);
  }
  /*printf("Menor entrada na posicao %d de valor %d.\n",
    menorentrada(10,v),menorvalor(10,v));*/


  /*Para ponteiros em Linux pode usar %p
  printf("End v: %p\n",v);
  */

  /*for (i=0;i<1000;i++) {
    printf("%do=%d\n",i,(&i)[i]);
  };*/

  return 0;
}

int minoftwo(int a, int b) {
  if (a<b) {
    return a;
  }
  else {
    return b;
  }
}

int menorvalor (int n,int a[]){
  /*n=tamanho de a*/
  if (n==1) {
    return a[0];
  }
  else {
    int b[n-1];
    int i;
    for (i=0;i<n-1;i++) {
      b[i]=a[i+1];
    }
    return minoftwo(a[0],menorvalor(n-1,b));
  }
}

int menorentrada (int n,int a[]){
  /*Encontra a entrada de menor valor de um vetor.*/
  /*n=tamanho de a*/
  if (n==1) {
    return 0;
  }
  else {
    /*Cria um novo vetor sem a primeira entrada de a.*/
    int b[n-1];
    int i;
    for (i=0;i<n-1;i++) {
      b[i]=a[i+1];
    }
    int m=menorentrada(n-1,b);
    if (a[0]<=b[m]) {
      return 0;
    }
    else {
      return m+1;
    }
  }
}

int * selection_sort(int n, int a[]) {
  /*n=comprimento de a*/
  /*Faz selection sort*/
  if (n==1) {
    return a;
  }
  else {
    /*Copia o vetor a*/
    int c[n],i;
    for (i=0;i<=n-1;i++) {
      c[i]=a[i];
    }
    /*Põe a menor entrada de c na frente*/
    int m=menorentrada(n,c);
    int x=c[m];
    c[m]=c[0];
    c[0]=x;
    /*Cria um novo vetor sem a primeira entrada de c.*/
    int b[n-1];
    for (i=0;i<n-1;i++) {
      b[i]=c[i+1];
    }
    /*Arruma o resto*/
    int* v=selection_sort(n-1,b);
    /*Põe as entradas de volta em c*/
    for (i=1;i<=n-1;i++) {
      c[i]=v[i-1];
    }
  }
}
