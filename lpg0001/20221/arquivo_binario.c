#include <stdio.h>
#include <stdlib.h>

int main (int argc, int* argv[]) {
    
    /*
    int v[5] = {1,2,3,4,5};
    
    FILE* fp = fopen( "teste.bin" , "wb");

    int i;
    for (i=0;i<5;i++) {
        fwrite(v+i,sizeof(int),argc,fp);
    }

    fclose(fp);
    //fwrite ( endereço de armazenamento , tamanho da memoria , numero de blocos , arquivo a ser gravado)
    */
    //idem fread(...)

    int v[5];
    int i;

    FILE* fp = fopen( "teste.bin" , "rb");

    for (i=0;!feof( fp );i++) {
        fread(v+i,sizeof(int),1,fp);
    }

    for (i=0;i<5;i++) {
        printf("%d",v[i]);
    }

    return 0;
}