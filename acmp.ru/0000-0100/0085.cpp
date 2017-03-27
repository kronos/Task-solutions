#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int i,j;
    cin >> i >> j;
    while (i!=j)
    {
        if (i>j)
            i-=j;
        else
            j-=i;
    }
    while (i--)
        cout << 1;
    return 0;
}
