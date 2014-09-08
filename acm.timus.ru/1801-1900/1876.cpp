#include <iostream>
using namespace std;

int main()
{
  int a,b,r1,r2;
  cin >> a >> b;
  r1 = 39*2+40+(a-40)*2+1;
  r2 = b*2+40;
  if (r1 > r2)
    cout << r1 << endl;
  else
    cout << r2 << endl;
  return 0;
}
