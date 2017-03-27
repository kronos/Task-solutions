#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    string s;
    int n;
    cin >> s >> n;
    if (s=="Home")
    {
        cout << "Yes";
    }
    else
    {
        if (n%2)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}
