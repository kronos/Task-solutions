#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;
vector<int> d;
int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    string;
    int n,x,i;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> x;
        d.push_back(x);
    }
    if (!next_permutation(d.begin(),d.end()))
    {
        sort(d.begin(),d.end());
    }
    for (int i=0;i<n;i++)
    {
        cout << d[i] << ' ';
    }
    return 0;
}
