#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//include <stdarg.h> // function arguments
//#include <string.h>

void * _memcpy ( void * destination , void * source , size_t size ) {
    for ( int i=0 ; i<size ; i++ ) {
        ((char*)destination)[i]=((char*)source)[i];
    }
    return destination;
}

void swap ( void * A, void * B , size_t size) {
    //Swaps whatever is being pointed to by A and B, n being the size of the data in bytes.
    unsigned char temp[size];
    memcpy(temp,A,size);
    memcpy(A,B,size);
    memcpy(B,temp,size);
};

int max_int( int a , int b) {
    return (a>b) ? a : b;
}

int main ( int argc , char ** argv ) {
    int A=atoi(argv[1]);
    int B=atoi(argv[2]);
    printf("Os argumentos foram %d e %d.\n",A,B);

    swap(&A,&B,sizeof(int));

    printf("Em ordem trocada eles sao %d e %d.\n",A,B);

    return 0;
}
