#include <stdio.h>
#include <stdlib.h>
#include "dep_trabalho2.h"


int main(int argc, char* argv[]) {
    printf("Input a string");
    char* str = input_string(stdin);
    printf("%s",str);
    free(str);
    return 0;
}