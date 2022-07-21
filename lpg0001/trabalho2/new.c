#include <stdio.h>
#include <stdlib.h>
#include "dep_trabalho2.h"


int main(void){
    char *m;

    printf("input string : ");
    FILE* fp = fopen("agendas.txt","rt");
    m = input_string(stdin);
    printf("%s\n", m);

    free(m);
    return 0;
}