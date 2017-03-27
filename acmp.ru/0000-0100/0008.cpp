#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int s1,s2,s3;
int main()
{
   in >> s1 >> s2 >> s3;
   if (s1*s2==s3)
      out << "YES";
   else
      out << "NO";
   return 0;
}
