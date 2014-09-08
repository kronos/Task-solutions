#include <iostream>

using namespace std;

int j,i,n;
int m[100][100];

int main()
{
  cin >> n;
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      cin >> m[i][j];
  for (i=0;i<n;i++)
  {
    for (j = 0;j<i+1;j++)
      cout << m[i-j][j] << " ";
  }
  for (j=1;j<n;j++)
  {
    for (i = n-1;i>=j;i--)
      cout << m[i][n-i+j-1] << " ";
  }
  return 0;
}
