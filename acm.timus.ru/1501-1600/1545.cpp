#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int N,i;
  vector<string> a[28];
  cin >> N;
  string s;
  for (i=0;i<N;i++)
  {
    cin >> s;
    a[s[0]-'a'].push_back(s);
  }
  char c;
  cin >> c;
  c-='a';
  for (i=0;i<a[c].size();i++)
  {
    cout << a[c][i];
    cout << endl;
  }
  return 0;
}
