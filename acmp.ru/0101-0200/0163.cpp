#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int a;
    string s;
    cin >> s;
    if (s[0]=='x')
    {
        if (s[1]=='+')
            a = s[4]-'0'-(s[2]-'0');
        else
            a = s[2]-'0'+s[4]-'0';
    }
    else if (s[2]=='x')
    {
        if (s[1]=='+')
            a = s[4]-'0'-(s[0]-'0');
        else
            a = s[0]-'0'-(s[4]-'0');
    }
    else
    {
        if (s[1]=='+')
            a = s[0]-'0'+s[2]-'0';
        else
            a = s[0]-'0'-(s[2]-'0');
    }
    cout << a;
    return 0;
}
