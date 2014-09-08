#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  char c;
  string s;
  cin >> s;
  if (s.length() == 3)
  {
    n = (s[0] - '0')*10 + s[1] - '0';
    c = s[2];
  }
  else
  {
    n = s[0] - '0';
    c = s[1];
  }

  if (n < 3)
  {
    // A BC D
    if (c == 'A' || c== 'D')
    {
      cout << "window" << endl;
    }
    else
    {
      cout << "aisle" << endl;
    }
  }
  // AB CD EF
  else if (n < 21)
  {
    if (c == 'A' || c== 'F')
    {
      cout << "window" << endl;
    }
    else
    {
      cout << "aisle" << endl;
    }
  }
  else
  {
    // 123 4567 890
    // ABC DEFG HJK
    if (c == 'A' || c== 'K')
    {
      cout << "window" << endl;
    }
    else if (c=='B' || c=='E' || c=='F' || c=='J')
    {
      cout << "neither" << endl;
    }
    else
    {
      cout << "aisle" << endl;
    }
  }
  return 0;
}

