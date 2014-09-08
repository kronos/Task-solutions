#include <iostream>
#include <set>
using namespace std;
set<int> a,b,c,r;

int main()
{
  int i,n,x;
  cin >> n;
  for (i=0; i<n; ++i)
  {
    cin >> x;
    a.insert(x);
  }
  cin >> n;
  for (i=0; i<n; ++i)
  {
    cin >> x;
    if (a.find(x) != a.end())
    {
      b.insert(x);
    }
  }
  cin >> n;
  for (i=0; i<n; ++i)
  {
    cin >> x;
    if (b.find(x) != b.end())
    {
      c.insert(x);
    }
  }
  cout << c.size() << endl;
  return 0;
}
