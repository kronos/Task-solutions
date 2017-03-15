#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n,i,v;
  cin >> n;
  vector<int> a(n);
  vector<int>::iterator it;
  for (i=0; i<n;i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int max = *a.rbegin();
  for (i = 0; i < n-1 && a[i] < max; i++)
  {
    if (a[i] != 1 && a[i] < a[i+1] && a[i]*2 > a[i+1])
    {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
    return 0;
}
