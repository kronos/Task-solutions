#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int A,B,C,D,i;
int main()
{
   in >> A >> B;
   if (A==B)
      out << "=";
   else if (A>B)
      out << ">";
   else
      out << "<";
   return 0;
}
