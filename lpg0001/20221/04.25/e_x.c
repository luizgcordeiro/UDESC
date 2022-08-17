#include <stdio.h>

double taylor( float x, int n, int i,double termo);

int main () {
  float x;
  int n;
  printf("x=");
  scanf("%f",&x);
  printf("n=");
  scanf("%d",&n);
  double e_x=taylor(x,n,0,1);
  printf("%.15lf\n",e_x);
  return 0;
}

double taylor( float x, int n, int i,double termo) {
  if (i<=n) {
    return termo+taylor(x,n,i+1,termo*x/(i+1));
  }
  return 0;
}
