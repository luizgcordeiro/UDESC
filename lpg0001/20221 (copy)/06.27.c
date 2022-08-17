#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int a, *p1, **p2;

    a=3;

    p1=&a;
    p2=&p1;

    printf("Endereço de a: %p\n",p1);
    printf("Endereço de a: %p\n",*p2);
    return 0;
}