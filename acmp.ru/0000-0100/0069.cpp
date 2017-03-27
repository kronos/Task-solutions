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
    int N;
    double A,R,r;
    cin >> N >> A;
    R = sin(3.141592653589/N);
    R = A/(R*2);
    A/=2.0;
    r = sqrtf(R*R-A*A);
    if (abs(R-r)<1.0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
