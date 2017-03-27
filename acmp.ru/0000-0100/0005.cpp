#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
vector<int> even;
vector<int> odd;
int main()
{
   int N;
   in >> N;
   int i,t;
   for(i=0;i<N;i++)
   {
      in >> t;
      if (t%2==1)
     odd.push_back(t);
      else
     even.push_back(t);
   }
   for(i=0;i<odd.size();i++)
      out << odd[i] << " ";
   out << endl;
   for(i=0;i<even.size();i++)
      out << even[i] << " ";
   out << endl;
   if (even.size()>=odd.size())
      out << "YES";
   else
      out << "NO";
   return 0;
}
