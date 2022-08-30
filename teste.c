#include <stdio.h> 
#include <stdlib.h>

long max(long a, long b) {
    return  a>b ? a : b;
}

long max_or(long a, long b) {
    if (a>b) {
        return a;
    }
    return b;
}

#include <stdio.h>
 
#include <stdio.h>
 
 
#include <stdio.h>
 
int main() {
 
    int l,i,j,c;
    char D,N[100],M[100];
    scanf("%c %s",&D,N);
    while ((c=getchar())!='\n' && c!=EOF);
    
    while (D!='0' || N[0]!='0' || N[1]!=0) {
        l=0;
        while (N[l]!=0) l++;
        //Ao inves de apagar as entradas de N, vamos copiar as restantes para M
        for (i=0,j=0;i<=l;i++) {//Poe <=l para copiar o fim de string
            if (N[i]!=D) {
                M[j++]=N[i];
            }
        }
        //j=len(M);
        
        //Ignora os zeros iniciais
        i=0;
        while (M[i]=='0') i++;
        
                
        //M[i] é a primeira entrada != 0 (numero).
        //Pode ser que M[i]=0;
        
        if (M[i]==0) {
            M[i]='0';
            M[i+1]=0;
        }

        printf("%s\n",M+i);
        
        scanf("%c %s",&D,N);
        while ((c=getchar())!='\n' && c!=EOF);
    }
    return 0;
}