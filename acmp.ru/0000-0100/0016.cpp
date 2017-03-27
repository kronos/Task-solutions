#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

long long rr[250][500];

long long count(int l, int r)
{
   if (rr[l][r]!=-1)
      return rr[l][r];
   long long &q = ++rr[l][r];
   while (l<r)
   {
      q+=1+count(l+1,r-1);
      l++;
      r-=l;
   }
   return q;
}

int main()
{
   long long i,j,N;
   for (i=0;i<250;i++)
      for (j=0;j<500;j++)
     rr[i][j] = -1;
   in >> N;
   out << count(1,N-1)+1;
   return 0;
}
