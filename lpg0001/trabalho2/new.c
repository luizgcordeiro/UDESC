#include <stdio.h>
#include <stdlib.h>
#include "dep_trabalho2.h"


int main(int argc, char* argv[]) {
    printf("%s",argv[1]);
    printf("\n");
    printf("%s",argv[2]);
    printf("\n");
    printf("%d",e_substring(argv[1],argv[2]));
    return 0;
}