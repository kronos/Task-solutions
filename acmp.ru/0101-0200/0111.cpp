#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
int find(int K)
{
    int i;
    if (K%2==1)
    {
        int q = sqrtf(K);
        for (i=3;(K%i!=0) && (i<=q);)
            i+=2;
        return K%i==0 ? i : K;
    }
    else
    {
        if ((K & (K-1))==0)
            return K;
        //K/=2;
        if ((K/2)%2)
            return find(K/2);
        for (i=3;K%i!=0;)
            i++;
        return find(i);
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int K,i;
    cin >> K;
    if (K<3)
        cout << 0;
    else
        cout << find(K)-1;
    return 0;
}
