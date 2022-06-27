#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

void imprimir_vetor_float(float *v, int n);//Funçãozinha útil
int strlen_meu(char str[]);//Idem
float *clone( float *v, int n );//Exercício 1
char *repetidor( char *s, int n );//Exercício 2
float media(float * v,int n);//Exercício 3.1
float * maiorig_que (float * v,int n,float x);//Exercício 3.2

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
            printf("Qual o tamanho do vetor que você quer criar (no máximo %d)? ",MAX);
            int n;
            scanf("%d",&n);

            float * v=malloc(sizeof(float)*n);

            srand(time(NULL));

            int i;

            for (i=0;i<n;i++) {
                v[i]=(float)rand()/RAND_MAX;//número aleatório entre 0 e 1
                v[i]*=20;//Número aleatório entre 0 e 20
                v[i]-=10;//Número aleatório entre -10 e 10;
            }
            
            printf("O vetor é\n");
            imprimir_vetor_float(v,n);
            printf("\nalocado na posição %p da memória.\n\n",v);

            float * p = clone(v,n);
            printf("A cópia desse vetor é\n");
            imprimir_vetor_float(p,n);
            printf("\ne está alocado na posição %p da memória.\n",p);
            free(v);
            free(p);
        }

        else if (num_ex==2) {
            char str[500];
            printf("Digite uma string (ate 500 caracteres) para fazer copias:\n");
            //scanf(" %[^\n]%*c", str);
            //Tem que ser um pouco diferente do acima para nao apagar espacos no comeco
            int cc;
            while ( (cc = getchar()) != '\n' && cc != EOF );

            fgets(str,500,stdin);

            str[strlen_meu(str)-1]=0;

            int n;
            printf("Quantas vezes voce quer copiá-la? ");
            scanf("%d",&n);
            char * str_repetida=repetidor(str,n);

            printf("A string repetida %d vezes é\n%s\n",n,str_repetida);
            free(str_repetida);
        }

        else if (num_ex==3) {
            printf("Qual o tamanho do vetor que você quer criar (no máximo %d)? ",MAX);
            int n;
            scanf("%d",&n);

            float * v=malloc(sizeof(float)*n);

            srand(time(NULL));

            int i;

            for (i=0;i<n;i++) {
                v[i]=(float)rand()/RAND_MAX;//número aleatório entre 0 e 1
                v[i]*=20;//Número aleatório entre 0 e 20
                v[i]-=10;//Número aleatório entre -10 e 10;
            }
            
            printf("O vetor é\n");
            imprimir_vetor_float(v,n);
            printf("\n");

            float med=media(v,n);

            printf("A media dos valores é %.4f.\n",med);

            float* maiores_que_media=maiorig_que(v,n,med);

            printf("O subvetor com entradas maiores ou iguais à média é\n");
            imprimir_vetor_float(maiores_que_media,sizeof(maiores_que_media)/sizeof(float));

            free(maiores_que_media);
            free(v);

            printf("\n");
        }

        else if (num_ex==4) {
            
        }

        else if (num_ex==5) {
            
        }
        printf("=============\n");
    }

    return 0;
}

float *clone( float *v, int n ) {
    float * p = malloc(sizeof(float)*n);

    int i;
    for (i=0;i<n;i++) {
        p[i]=v[i];
    }

    return p;
}

char *repetidor( char *s, int n ) {
    int len=strlen_meu(s);
    int new_len=n*len;

    char* str=malloc(len*n+1);

    int i,j=0;
    for (i=0;i<new_len;) {
        for (j=0;j<len;) {
            str[i]=s[j];
            i++;
            j++;
        }
    }

    str[i]=0;

    return str;
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

float * maiorig_que (float * v,int n,float x) {
    int cont=0,i,j=0;
    for (i=0;i<n;i++) {
        cont+=(int)(v[i]>=x);
    }

    float * out=malloc(sizeof(float)*cont);

    for (i=0;i<n & j<cont;i++) {
        if (v[i]>=x) {
            out[j]=v[i];
            j++;
        }
    }
    return out;
}