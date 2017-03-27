#include <cmath>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
struct lng
{
   int a[500];

   const lng operator = (const int right)
   {
      for(int i=0;i<500;i++)
     a[i] = 0;
      a[499] = right;
      return *this;
   }

   const lng operator *= (const int right)
   {
      int c = 0;
      for(int i=499;i>=0;i--)
      {
     a[i] = a[i]*right+c;
     c = a[i]/10;
     a[i]=a[i]%10;
      }
      return *this;
   }
};

lng a;
int main()
{

   int n,i;
   a = 2;
   in >> n;
   for(i=1;i<n;i++)
      a*=2;
   for(i=0;a.a[i]==0;)
      i++;

   for(;i<500;i++)
      out << a.a[i];

   return 0;
}
