#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    string s;
    long long n,o,l,k;
    cin >> n >> s;
    l = s.length();
    k = l;
    o = n;
    while (o>k)
    {
        n*=(o-k);
        k+=l;
    }
    cout << n;
    return 0;
}
