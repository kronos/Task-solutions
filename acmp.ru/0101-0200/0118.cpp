#include <fstream>
#include <vector>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
vector<int> v;
int main()
{
    int n,l=0,i=1,k;
    in >> n >> k;
    for (;i<=n;i++)
        v.push_back(i);
    for (i=n;i>1;i--)
    {
        l = (l+k-1)%i;
        v.erase(v.begin()+l);
    }
    out << v[0];
    return 0;
}
