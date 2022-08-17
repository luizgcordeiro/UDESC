#include <stdio.h>
#include <stdlib.h>
#include <time.h>

srand(time(NULL));

int main ( int argc , char ** argv ) {
    printf("%8.3f",3.1415926535);
    printf("\n");
    printf("%5.3f",12356873.1415926535);

    return 0;
}