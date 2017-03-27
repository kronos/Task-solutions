#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

int a[1441];
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n,i,l,ans=0;
    cin >> n;
    string s;
    for(i=0;i<n;i++)
    {
        cin >> s;
        l = (s[0]-'0')*600+(s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
        a[l]++;
        cin >> s;
        l = (s[0]-'0')*600+(s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
        a[l+1]--;
    }
    l = 0;
    for (i=0;i<1440;i++)
    {
        l+=a[i];
        if (l>ans)
            ans = l;
    }
    cout << ans;
    return 0;
}
