#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <stdarg.h> // function arguments
//#include <math.h> // math
//#include <string.h>


double max(double x, double y) {
    //valor maximo
    return (x>y) ? x : y;
}

#include <stdio.h>

/*int main (int argc, char ** argv) {
    int T,PA,PB;
    double G1 , G2;
    scanf("%d",&T);

    for (int num_testes=0;num_testes<T;num_testes++) {
        scanf("%d %d %lf %lf",&PA,&PB,&G1,&G2);
        int tempo=0;
        while (PA<=PB && tempo<=100) {
            tempo++;
            PA=PA+(int)(PA*G1)/100;
            PB=PB+(int)(PB*G2)/100;
        }
        if (tempo<=100) {
            printf("%d anos.\n",tempo);
        } else {
            printf("Mais de 1 seculo.\n");
        }
    }
    return 0;
}*/

#include <stdio.h>

#include <stdio.h>

int main() {
    int N,X;
    
    scanf("%d",&N);
    
    for (int cases=0;cases<N;cases++) {
        scanf("%d",&X);
        int div;
        for (div=2;div<X;div++) {
            if (X%div==0) {
                printf("%d nao eh primo\n",X);
                break;
            }
        };
        
        if (div==X || X==1) {
            printf("%d eh primo\n",X);
        }
    }
    
    return 0;
}