#include <stdio.h>
#include <math.h>

unsigned int k,i,j,n;
int main()
{
  scanf("%d",&n);
  k = 2;j = 2;
  for (i=2;i<n;i++){
    j = k+j;
    k = j-k;
  }
  printf("%u",j);
  return 0;
}
