#include <fstream>
#include <cmath>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
bool prime(int x)
{
    if (x%2==0)
        return false;
    int i,p = sqrtf(x);
    bool f = true;
    for (i=3;(i<=p)&&(f);i+=2)
        f = x%i!=0;

    return f;
}
int main()
{
    int n,i,r=0;
    in >> n;
    for (i=n+1;i<n*2;i++)
        if (prime(i))
            r++;
    out << r;
    return 0;
}
