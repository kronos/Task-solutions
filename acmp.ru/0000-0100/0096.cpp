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
    int N,M,d=0,i=1,j=1,x,y;
    cin >> N >> M;
    int l=1,r=M,t=1,b=N,rr=0;
    cin >>  y >> x;
    if (y==i)
    {
        rr++;
    }
    bool f = false;
    do
    {
        switch(d)
        {
            case 0:
                if (i!=y)
                {
                    rr+=r-l+1;
                    j = r;
                    t++;
                }
                else
                {
                    rr+=x-j;
                    f = true;
                }
            break;
            case 1:
                if (x!=j)
                {
                    rr+=b-t+1;
                    i = b;
                    r--;
                }
                else
                {
                    rr+=y-i;
                    f = true;
                }
            break;
            case 2:
                if (y!=i)
                {
                    rr+=r-l+1;
                    j = l;
                    b--;
                }
                else
                {
                    rr+=j-x;
                    f = true;
                }
            break;
            case 3:
                if (x!=j)
                {
                    rr+=b-t+1;
                    i = t;
                    l++;
                }
                else
                {
                    rr+=i-y;
                    f = true;
                }

            break;
        }
        d++;
        d%=4;
    }
    while(!f);
    cout << rr;
    return 0;
}
