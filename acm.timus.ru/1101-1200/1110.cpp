#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int i,N,M,Y,k,j;
vector<int> r;
vector<int>::iterator it;
int main()
{
  cin >> N >> M >> Y;
  if (Y==1)
  {
    r.push_back(1);
  }
  for (i=2;i<M;i++)
  {
    k = i%M;
    for (j=1;(j<N)&&(k);j++)
      k = (k*i)%M;
    if (k==Y)
      r.push_back(i);
  }
  if (r.size()==0)
    cout << "-1";
  else
  {
    for (it=r.begin();it!=r.end();it++)
    {
      cout << (*it) << " ";
    }
  }
  return 0;
}
