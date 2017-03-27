#include <cmath>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int main()
{
   string s1,s2;
   int i,j;
   in >> s1 >> s2;
   int bull=0,cow=0;
   for(i=0;i<4;i++)
   {
      if (s1[i]==s2[i])
     bull++;
      else
     for(j=0;j<4;j++)
        if (s1[i]==s2[j])
        {
           cow++;
           break;
        }
   }
   out << bull << " " << cow;
   return 0;
}
