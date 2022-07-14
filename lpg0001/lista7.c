#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

void imprimir_vetor_float(float *v, int n);//Funçãozinha útil
void imprimir_vetor_int(int *v, int n);//Idem
int strlen_meu(char str[]);//Idem
int is_in(int x,int * v, int n);
int ** aloca_matriz_quadrada(int n);
int *diagonal_secundaria( int **matriz, int ordem );//Ex1
int ** prod_mat( int **A, int**B, int m, int n, int p);//Ex2

int main() {
    printf("=============\n");
    printf("LISTA 7\n");
    printf("=============\n");

    srand(time(NULL));

    int num_ex=1;
    while (num_ex!=0) {

        printf("Digite o numero do exercicio que voce quer testar (1 a 3)\n"
        "ou 0 para sair: ");
        scanf("%d",&num_ex);

        if (num_ex==1) {
            printf("Qual o tamanho da matriz que voce quer criar (no maximo %d)? ",MAX);
            int n;
            scanf("%d",&n);

            int ** matriz=aloca_matriz_quadrada(n);

            int i,j;
            for (i=0;i<n;i++) {
                for (j=0;j<n;j++) {
                    matriz[i][j]=rand()%20;
                }
            }

            printf("A matriz foi criada, e os seus valores selecionados aleatoriamente:\n");

            for (i=0;i<n;i++) {
                for(j=0;j<n;j++) {
                    printf("%4d",matriz[i][j]);
                }
                printf("\n");
            }
            printf("no  espaco de memoria %p.\n",matriz);

            int * diag_sec = diagonal_secundaria(matriz,n);

            printf("A diagonal secundaria e\n");
            
            for (i=0;i<n;i++) {
                printf("%4d",diag_sec[i]);
            }
            printf("\n");

            free(diag_sec);
            for (i=0;i<n;i++) {
                free(matriz[i]);
            }

            free(matriz);
        }

        else if (num_ex==2) {
            printf("Vamos criar duas matrizes A e B cujo produto AB pode ser calculado.\n");
            printf("Quantas linhas voce quer que A tenha? ");
            int m;
            scanf("%d",&m);
            printf("Quantas colunas voce quer que A tenha? (Este tambem sera o numero de linhas de B.) ");
            int n;
            scanf("%d",&n);
            printf("Quantas colunas voce quer que B tenha? ");
            int p;
            scanf("%d",&p);

            int ** A=malloc(m*sizeof(int*));

            int i,j;
            for (i=0;i<m;i++) {
                A[i]=malloc(n*sizeof(int*));
                for (j=0;j<n;j++) {
                    A[i][j]=rand()%20;
                }
            }

            int ** B=malloc(n*sizeof(int*));
            for (i=0;i<n;i++) {
                B[i]=malloc(p*sizeof(int*));
                for (j=0;j<p;j++) {
                    B[i][j]=rand()%20;
                }
            }

            printf("As matrizes foram criadas aleatoriamente.\n");

            printf("A=");
            for (i=0;i<m;i++) {
                for(j=0;j<n;j++) {
                    printf("%4d",A[i][j]);
                }
                printf("\n  ");
            }

            printf("\nB=");
            for (i=0;i<n;i++) {
                for(j=0;j<p;j++) {
                    printf("%4d",B[i][j]);
                }
                printf("\n  ");
            }

            int ** AB=prod_mat(A,B,m,n,p);

            printf("\nO produto AB e\n");
            for (i=0;i<m;i++){
                for (j=0;j<p;j++){
                    printf("%4d",AB[i][j]);
                }
                printf("\n");
            }

            for (i=0;i<m;i++){
                free(A[i]);
                free(AB[i]);
            }

            for (i=0;i<n;i++){
                free(B[i]);
            }
        }

        else if (num_ex==3) {
            int N,i,j;
            printf("Este programa recebe uma quantidade de numeros naturais e determina seus divisores.\n");

            printf("De quantos naturais voce quer determinar divisores?: ");
            scanf("%d",&N);

            int ** p=malloc(N*sizeof(int*));

            printf("Voce quer escolher os numeros naturais aleatoriamente? (S/N) ");
            char resp;
            scanf("%c",&resp);
            while (resp!='S'&& resp!='N') {
                scanf("%c",&resp);
            }
            for (i=0;i<N;i++) {
                int n;
                
                if (resp=='S') {
                    n=(rand()%(10*N))+1;
                }
                else {
                    printf("Digite o %do numero inteiro a determinar divisores: ",i+1);
                    scanf("%d",&n);
                }
                p[i]=malloc(n*sizeof(int)+1);
                p[i][0]=n;
                int numero_de_divisores=0;
                //Vamos achar os divisores
                int d;
                for (d=1;d<=n;d++) {
                    if (n%d==0) {
                        numero_de_divisores++;
                        p[i][numero_de_divisores]=d;
                    }
                }

                p[i]=realloc(p[i],numero_de_divisores*sizeof(int)+2);
                p[i][numero_de_divisores+1]=0;
            }

            for (i=0;i<N;i++) {
                printf("Divisores de %d: ",p[i][0]);
                j=1;
                while (p[i][j+1]!=0){
                    printf("%d, ",p[i][j]);
                    j++;
                }
                printf("%d.\n",p[i][j]);
            }


            for (i=0;i<N;i++) {
                free(p[i]);
            }
            free(p);
        }
        printf("=============\n");
    }

    return 0;
}

void imprimir_vetor_float(float *v, int n) {//Imprime o vetor float v de tamanho n
    printf("[");
    int i;
    for (i=0;i<n-1;i++) {
        printf("%.4f,",v[i]);
    }
    printf("%.4f]",v[n-1]);

    return;
}

void imprimir_vetor_int(int *v, int n) {//Imprime o vetor inteiro v de tamanho n
    printf("[");
    int i;
    for (i=0;i<n-1;i++) {
        printf("%d,",v[i]);
    }
    printf("%d]",v[n-1]);

    return;
}

int strlen_meu(char str[]) {
  if (str[0]=='\0') {
    return 0;
  }

  return 1+strlen_meu(str+1);
}

float media(float * v,int n) {
    float sum=0;
    int i;
    for (i=0;i<n;i++) {
        sum+=v[i];
    }

    return sum/n;
}

int ** aloca_matriz_quadrada(int n) {
    int ** p=malloc(n*sizeof(int*));
    int i;
    for (i=0;i<n;i++) {
        p[i]=malloc(n*sizeof(int));
    }
    return p;
}

int *diagonal_secundaria( int **matriz, int ordem ) {
    int * diag = malloc(ordem*sizeof(int));
    int i;
    for (i=0 ; i<ordem ; i++) {
        diag[i]=matriz[i][ordem-1-i];
    }

    return diag;
}

int ** prod_mat( int **A, int**B, int m, int n, int p) {
    int ** prod = malloc(m*sizeof(int*));

    int i,j,k;
    for (i=0;i<m;i++) {
        prod[i]=malloc(p*sizeof(int));
    }

    for (i=0;i<m;i++) {
        for (j=0;j<p;j++) {
            prod[i][j]=0;
            for (k=0;k<n;k++) {
                prod[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    return prod;
}