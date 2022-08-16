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

int main(int argc, char **argv) {
    long a=strtol(argv[1],NULL,10);
    long b=strtol(argv[2],NULL,10);
    printf("%d",max(a,b));
    return 0;
}

i=2

i++