#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int i,j,m;
    string s;
    cin >> s;
    next_permutation(s.begin(),s.end());
    cout << s;
    return 0;
}
