#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
string s="";
int n,p=1;
bool prime(int p)
{
    if (p==2)
        return true;
    if (p%2==0)
        return false;
    int pr = sqrtf(p);
    bool f = true;
    for(int i=3;(i<=pr)&&(f);i++)
    {
        f = p%i!=0;
    }
    return f;
}

int gen(int p)
{
    while (!prime(p))
        p++;
    return p;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int T,n;
    string s,s1;
    stringstream ss;
    while (s.length()<=10000)
    {
        ss.clear();
        p = gen(p+1);
        ss << p;
        ss >> s1;
        //s1 = ' '+s1;
        s+=s1;
    }

    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << s[n-1];
    }

    return 0;
}
