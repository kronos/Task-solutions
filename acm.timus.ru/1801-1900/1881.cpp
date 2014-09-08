#include <iostream>
#include <string>
using namespace std;

int main()
{
  int h,w,n, al = 1, i, cw,l;
  string s;
  cin >> h >> w >> n;

  cin >> s;
  cw = s.length();
  for (i=1; i < n; i++)
  {
    cw++; // space
    cin >> s;
    l = s.length();
    if (cw + l > w)
    {
      al++;
      cw = l;
    }
    else
    {
      cw += l;
    }
  }

  if (al <= h)
  {
    cout << 1 << endl;
  }
  else
  {
    if ((al % h) == 0)
      cout << al/h << endl;
    else
      cout << al/h + 1 << endl;
  }
  return 0;
}
