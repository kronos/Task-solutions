#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
map<string,int> d;
map<string,int>::iterator it;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int n;
  cin >> n;
  string s;
  getline(cin,s);
  for(int i=0;i<n;i++)
  {
    getline(cin,s);
    d[s]++;
  }
  string r;
  int mmax = -1;
  for (it=d.begin();it!=d.end();it++)
    if (it->second>mmax)
    {
      r = it->first;
      mmax = it->second;
    }
    cout << r;
  return 0;
}
