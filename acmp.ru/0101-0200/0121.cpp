#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, N;
int sum[102][2];
vector<int> arr(102);

int find(int ind, bool f, int s)
{
    if (ind>N)
        return 0;

    if (sum[ind][f]!=100000)
        return sum[ind][f];
    int a,b,p;

    if (f)
    {
        p = arr[ind+1]-arr[ind];
        a = p+find(ind+1, false, s+p);
        p = arr[ind]-arr[ind-1];
        b = p+find(ind+1, true, s+p);
    }
    else
    {
        p = arr[ind+1]-arr[ind];
        a = find(ind+1, false, s+p)+p;
        b = find(ind+1, true, s);
    }
    sum[ind][f] = min(a,b);
    return min(a,b);
}

int main(int argc, char** argv)
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    cin >> N;
    int i;
    for (i=1; i<=N; i++)
    {
        cin >> arr[i];
        sum[i][0] = 100000;
        sum[i][1] = 100000;
    }
    arr[0] = -10005;
    arr[N+1] = 100000;
    sort(arr.begin(), arr.begin()+N+1);
    if (N==1)
    {
        cout << 0;
        return 0;
    }
    cout << find(1, true, 0) << endl;
    return 0;
}
