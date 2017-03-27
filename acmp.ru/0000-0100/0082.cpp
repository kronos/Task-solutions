#include <iostream>
using namespace std;
int i,N,M,t[100001],x;
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    cin >> N >> M;
    for(i=0;i<N;i++)
    {
        cin >> x;
        t[x] = 1;
    }
    for(i=0;i<M;i++)
    {
        cin >> x;
        if (t[x]==1)
            t[x] = 2;
    }
    for (i=0;i<=100000;i++)
        if (t[i]==2)
            cout << i << " ";
    return 0;
}
