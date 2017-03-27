#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
int k;
using namespace std;
bool compare(vector<int> now,vector<int> need)
{
    bool f = true;
    for (int i=0;(i<k)&&(f);i++)
        f = now[i] == need[i];

    return f;
}
int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int n,i,add;
    cin >> n >> k;
    vector<int> need(k),now(n);
    for (i=0;i<k;i++)
    {
        now[i] = i+1;
        cin >> need[i];
    }
    for (;i<n;i++)
        now[i] = i+1;
    int ans = 1,q,j;
    vector<int>::iterator it = now.end()-(n-k);
    while (!compare(now,need))
    {
        ans++;
        sort(it,now.end());
        reverse(it,now.end());
        next_permutation(now.begin(),now.end());
    }
    cout << ans;
    return 0;
}
