#include <iostream>
#include <stdio.h>
using namespace std;
int N,c=0,i,k;
int main()
{
  cin >> N;
  for (i=0;i<N;i++)
  {
    cin >> k;
    c+=k;
  }
  printf("%.6f",(double)c/N);
  return 0;
}
