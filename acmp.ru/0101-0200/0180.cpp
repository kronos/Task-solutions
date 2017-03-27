#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <sstream>
using namespace std;
int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);

    int N,n,i=9;
    string s,s1;
    cin >> N >> n;
    char p;
    if (n==1)
        s = "1";
    else
        for (;i>1;i--)
            while (n%i==0)
            {
                n/=i;
                p = i+'0';
                s=p+s;
            }
            if (n!=1)
                cout << "NO";
            else
            {
                stringstream ss;
                ss << N;
                ss >> s1;
                if (s1.length() > s.length() || (s1.length()==s.length() && s1>=s))
                    cout << "YES";
                else
                    cout << "NO";
            }

    return 0;
}
