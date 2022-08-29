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

int strlen_ ( char * st ) {
    int i=0;
    while (st[i]!=0) i++;
    return i;
}

#include <stdio.h>
 
int case_ ( char c) {
    //0 minusculo; 1 maiusculo
    if (c<='Z') {
        return 1;
    }
    return 0;
}

void maiusculo (char *c) {
    if (case_(*c)==0) {
        *c += 'A'-'a';
        return;
    }
    return;
}

void minusculo (char *c) {
    if (case_(*c)==1) {
        *c +='a'-'A';
        return;
    }
    return;
}

int main() {
 
    int N,i,look_for_char=1;
    char c;
    scanf("%d ",&N);
    
    for (i=0;i<N;i++) {
        while((c=getchar())!=EOF && c!='\n') {
            if (look_for_char) {
                if (c!=' ') {
                    printf("%c",c);
                    look_for_char=0;
                }
            } else {
                if (c==' ') {
                    look_for_char=1;
                }
            }
        }
        
        if (c=='\n') {
            printf("\n");
        }
    }
 
    return 0;
}