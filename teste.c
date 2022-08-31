#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <stdarg.h> // function arguments
//#include <math.h> // math
//#include <string.h>

int mdc ( int x , int y) {
    if (x<0) return mdc(-x,y);
    if (y<0) return mdc(x,-y);
    if (x==y || y==0) return x;
    if (x<y) return mdc(y,x);
    return mdc(x-y,y);
};

int main(int argc, char **argv) {
    srand(time(NULL));
    int primos[]={2,3,5,7,11};
    int exp_a[5],exp_b[5];
    int i,j;
    int a=1,b=1;

    for (i=0;i<5;i++) {
        exp_a[i]=rand()%4;
        for (j=0;j<exp_a[i];j++) {
            a*=primos[i];
        }
        exp_b[i]=rand()%4;
        for (j=0;j<exp_b[i];j++) {
            b*=primos[i];
        }
    }

    printf("mdc(%d,%d)=%d",a,b,mdc(a,b));

    return 0;
}