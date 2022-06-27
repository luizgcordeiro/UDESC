#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

int main() {
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    int * w = {1,2,3,4,5,6,7,8,9,10};
    int * x = malloc(10*sizeof(int));

    printf("%d\n",sizeof(v));
    printf("%d\n",sizeof(w));
    printf("%d\n",sizeof(x));

    free(x);
    return 0;
}