#include <iostream>
using namespace std;
int r[] = {5, 20, 12, 2, 1, 4, 6, 1, 4, 4, 1, 0};
int main()
{
  int x,y;
  cin >> x >> y;
  if ((x % 2) == 0  || (y % 2) == 1)
  {
    cout << "yes" << endl;
  }
  else
  {
    cout << "no" << endl;
  }
  return 0;
}
