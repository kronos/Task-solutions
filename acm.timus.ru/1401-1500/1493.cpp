#include <iostream>

using namespace std;

int r;

int getleft(int r)
{
  return r%10+(r%100)/10+(r%1000)/100;
}

int getright(int r)
{
  int t =  r/100000;
  t+=(r/10000)%10;
  t+=(r/1000)%10;
  return t;
}
int main()
{
  cin >> r;
  r--;
  int rr,l;
  rr = getright(r);
  l = getleft(r);
  if (rr==l)
    cout << "Yes";
  else {
    r+=2;
    rr = getright(r);
    l = getleft(r);
    if (rr==l)
      cout << "Yes";
    else
      cout << "No";
  }
  return 0;
}
