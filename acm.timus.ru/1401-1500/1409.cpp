#include <stdio.h>
int x1,x2;
int main()
{
  scanf("%d %d",&x1,&x2);
  if (x1!=0)
    printf("%d %d \n",x2-1,x1-1);
  else
    printf("0 0 \n");
  return 0;
}
