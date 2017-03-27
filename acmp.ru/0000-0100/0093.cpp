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
ifstream in("input.txt");
ofstream out("output.txt");
vector<string> d,v;
vector<int> a;
int check(string s1, string s2)
{
    if (s1.length()!=s2.length())
        return 0;
    int r = 0;
    for (int i=0;i<s1.length();i++)
    {
        if (s1[i]!=s2[i])
            r++;
    }
    return r;
}
int main()
{
#ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
#endif
    int N,M,i,j,c;
    in >> N;
    string s;
    for (int i=0;i<N;i++)
    {
        in >> s;
        d.push_back(s);

    }
    in >> M;
    for (i=0;i<M;i++)
    {
        in >> s;
        v.push_back(s);
    }
    for (i=0;i<N;i++)
    {
        int c = 0;
        for (j=0;j<M;j++)
        {
            if (check(d[i],v[j])==1)
                c++;
        }
        a.push_back(c);
    }
    for (i=0;i<N;i++)
    {
        out << a[i] << " ";
    }

    return 0;
}
