#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

void imprimir_vetor_float(float *v, int n);//Funçãozinha útil
void imprimir_vetor_int(int *v, int n);//Idem
int strlen_meu(char str[]);//Idem
int is_in(int x,int * v, int n);
float *clone( float *v, int n );//Exercício 1
char *repetidor( char *s, int n );//Exercício 2
float media(float * v,int n);//Exercício 3.1
float * maiorig_que (float * v,int n,float x);//Exercício 3.2
int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );//Exercício 5

int main() {
    printf("LISTA 6\n");
    printf("\n");
    printf("=============\n");


    int num_ex=1;
    while (num_ex!=0) {

        printf("Digite o numero do exercicio que voce quer testar (1 a 7)\n"
        "ou 0 para sair: ");
        scanf("%d",&num_ex);

        if (num_ex==1) {
            printf("Qual o tamanho do vetor que voce quer criar (no maximo %d)? ",MAX);
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
            
            printf("O vetor e\n");
            imprimir_vetor_float(v,n);
            printf("\nalocado na posicao %p da memoria.\n\n",v);

            float * p = clone(v,n);
            printf("A copia desse vetor a\n");
            imprimir_vetor_float(p,n);
            printf("\ne esta alocado na posicao %p da memoria.\n",p);
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
            printf("Quantas vezes voce quer copia-la? ");
            scanf("%d",&n);
            char * str_repetida=repetidor(str,n);

            printf("A string repetida %d vezes e\n%s\n",n,str_repetida);
            free(str_repetida);
        }

        else if (num_ex==3) {
            printf("Qual o tamanho do vetor que voce quer criar (no maximo %d)? ",MAX);
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
            
            printf("O vetor e\n");
            imprimir_vetor_float(v,n);
            printf("\n");

            float med=media(v,n);

            printf("A media dos valores e %.4f.\n",med);

            float* maiores_que_media=maiorig_que(v,n,med);

            printf("O subvetor com entradas maiores ou iguais a media e\n");
            imprimir_vetor_float(maiores_que_media+1,(int)maiores_que_media[0]);

            free(maiores_que_media);
            free(v);

            printf("\n");
            printf("%d",(int)3.6);
        }

        else if (num_ex==4) {
            printf("Qual o tamanho do vetor que voce quer criar (no maximo %d)? ",MAX);
            int n;
            scanf("%d",&n);

            int * v=malloc(sizeof(int)*n);

            srand(time(NULL));

            int i;

            for (i=0;i<n;i++) {
                v[i]=rand()%(4*n);//inteiro aleatório entre 0 e 4n
                v[i]-=2*n;//Inteiro aleatório entre -2n e 2n
            }
            
            printf("O vetor e\n");
            imprimir_vetor_int(v,n);
            printf("\n");

            int cont_pos=0,cont_neg=0;
            for (i=0;i<n;i++) {
                if (v[i]>0) {
                    cont_pos++;
                }
                else if (v[i]<0) {
                    cont_neg++;
                }
            }

            int * v_pos = malloc(sizeof(int)*cont_pos);
            int * v_neg = malloc(sizeof(int)*cont_neg);

            int j=0,k=0;
            for (i=0;i<n;i++) {
                if (v[i]>0) {
                    v_pos[j]=v[i];
                    j++;
                }
                else if (v[i]<0) {
                    v_neg[k]=v[i];
                    k++;
                }
            }

            printf("\n");
            printf("O subvetor com as entradas positivas e\n");
            imprimir_vetor_int(v_pos,cont_pos);
            printf(",\ne o subvetor com as entradas negativas e\n");
            imprimir_vetor_int(v_neg,cont_neg);
            printf(".\n");

            free(v);
            free(v_pos);
            free(v_neg);
        }

        else if (num_ex==5) {
            printf("Qual o tamanho do primeiro conjunto que voce quer criar (no maximo %d)? ",MAX/2);
            int n1;
            scanf("%d",&n1);

            int * v1=malloc(sizeof(int)*n1);

            srand(time(NULL));

            int i;

            for (i=0;i<n1;i++) {
                v1[i]=rand()%(4*n1);//inteiro aleatório entre 0 e 4n1
                v1[i]-=2*n1;//Inteiro aleatório entre -2n1 e 2n1
                while (is_in(v1[i],v1,i)) {
                    v1[i]=rand()%(4*n1);//inteiro aleatório entre 0 e 4n1
                    v1[i]-=2*n1;//Inteiro aleatório entre -2n1 e 2n1
                }
            }

            printf("O conjunto e\n");
            imprimir_vetor_int(v1,n1);
            printf("\n");

            printf("Qual o tamanho do segundo conjunto que voce quer criar (no maximo %d)? ",MAX/2);
            int n2;
            scanf("%d",&n2);

            int * v2=malloc(sizeof(int)*n2);

            srand(time(NULL));

            for (i=0;i<n2;i++) {
                v2[i]=rand()%(4*n2);//inteiro aleatório entre 0 e 4n2
                v2[i]-=2*n2;//Inteiro aleatório entre -2n2 e 2n2
                while (is_in(v2[i],v2,i)) {
                    v2[i]=rand()%(4*n2);//inteiro aleatório entre 0 e 4n2
                    v2[i]-=2*n2;//Inteiro aleatório entre -2n2 e 2n2
                }
            }

            printf("O conjunto e\n");
            imprimir_vetor_int(v2,n2);
            printf("\n");

            int tamanho_uniao;

            int * conj_un;

            conj_un=uniao( v1, n1, v2, n2, &tamanho_uniao );

            printf("A uniao e\n");
            imprimir_vetor_int(conj_un,tamanho_uniao);
            printf("\ne tem cardinalidade %d.\n",tamanho_uniao);

            free(conj_un);
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

float * maiorig_que (float * v,int n,float x) {
    // n=tamanho de v
    // retorna subvetor de v que tem as entradas maiores do que x
    // Por razões técnicas, é bom salvar o tamanho como primeira coordenada (0)
    int cont=0,i,j=0;
    for (i=0;i<n;i++) {
        cont+=(int)(v[i]>=x);
    }

    float * out=malloc(sizeof(float)*(cont+1));
    out[0]=(float)cont;
    for (i=0;i<n && j<cont;i++) {
        if (v[i]>=x) {
            out[j+1]=v[i];
            j++;
        }
    }

    return out;
}

int * uniao( int *v1, int n1, int *v2, int n2, int *p3 ) {
    int * uniao=malloc(sizeof(int)*(n2));
    *p3=0;
    int j=0,i;

    //Primeiro, vamos fazer a diferença dos de v2 com v1 e gravar na uniao
    for (i=0;i<n2;i++) {
        if (!is_in(v2[i],v1,n1)) {
            uniao[*p3]=v2[i];
            (*p3)++;
        }
    }

    //Agora, realocamos para o tamanho apropriado.
    //Não vamos nos preocupar com o caso de faltar memória (não vai faltar, né)
    //*p3 é o tamanho da diferença;

    uniao = realloc(uniao,sizeof(int)*((*p3)+n1));

    for (i=0;i<n1;i++) {
        uniao[i+(*p3)]=v1[i];
    }

    *p3+=n1;
    return uniao;
}

int is_in(int x,int * v, int n) {//Checks if x is in vector v of size n
    if (n<=0) {
        return 0;
    }
    else if (x==v[0]) {
        return 1;
    }

    return is_in(x,v+1,n-1);
}