//#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <fstream>
using namespace std;
struct st
{
    int h,m,s;
    st(int _h,int _m,int _s):
        h(_h),m(_m),s(_s)
    {}
};
ifstream in("input.txt");
ofstream out("output.txt");
bool cmp(const st &l, const st &r)
{
    if (l.h==r.h)
    {
        if (l.m==r.m)
        {
            if (l.s==r.s)
            {
                return true;
            }else
                return l.s<r.s;
        }else
            return l.m<r.m;
    }else
        return l.h<r.h;
}
vector<st> t;
int main()
{
#ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
#endif
    int N,i,j,k,d,id,h,m,s;
    in >> N;
    for (int i=0;i<N;i++)
    {
        in >> h >> m >> s;
        st ss(h,m,s);
        t.push_back(ss);

    }
    sort(t.begin(),t.end(),cmp);
    for (int i=0;i<N;i++)
    {
        out << t[i].h << " " << t[i].m << " " << t[i].s << endl;
    }

    return 0;
}
