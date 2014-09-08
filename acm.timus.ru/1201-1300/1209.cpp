#include <stdio.h>
#include <math.h>
bool mas[65536];
double d,d1;
int i,n,k;

int main()
{
  scanf("%d",&n);
  for (i = 0; i<n; i++){
    scanf("%d",&k);
    d = sqrt( k-0.875 )*2.8284271247461903;
    mas[i] = (d<=double(int(d))+0.0000000001);
  }

  for (i = 0; i<n; i++)
    printf("%d ",mas[i]);

  return 0;
}
