#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int main()
{
   int x;
   in >> x;
   out << x << "9" << 9-x;
   return 0;
}
