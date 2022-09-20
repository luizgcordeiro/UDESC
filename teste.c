#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <stdarg.h> // function arguments
//#include <math.h> // math; -lm
#include <string.h>

/*int strcmp_(char *str1, char *str2) {
  int p;
  while ((str2[p] == str1[p]) && (str1[p] != 0)) p++;

  return *(int*)(str1+p) - *(int*)(str2+p);
}

void strcpy_(char * dest, char * src) {
  int i=0;
  while (src[i]) {
    dest[i]=src[i];
    i++;
  }
  dest[i]=0;
  return;
}*/
double det

int main(int argc, char **argv) {
    FILE * file=fopen("video.mp4","wb");

    srand(time(NULL));
    
    unsigned char x;
    for (int i=0;i<56646713;i++) {
        x=rand()%256;
        fwrite(&x,sizeof(char),1,file);
    }

    fclose(file);
    return 0;
}