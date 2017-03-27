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
string s;
vector<int> t;
int main()
{
  int i,m[100][100],n,j,r=0;
  in >> n;
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      in >> m[i][j];

  for (i=0;i<n;i++)
    for (j=i+1;j<n;j++)
      if (m[i][j])
        r++;
  out << r;

  return 0;
}
