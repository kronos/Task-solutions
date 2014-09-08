#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int r,i;
map<string,int>t;
map<string,int>::iterator it;
string s;

int main()
{
  cin >> r;
  for (i=0;i<r;i++)
  {
    cin >> s;
    t[s]++;
  }
  for (it=t.begin();it!=t.end();it++)
  {
    if (it->second>1)
      cout << it->first << endl;
  }
  return 0;
}
