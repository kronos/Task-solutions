#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
string s;
ifstream in("input.txt");
ofstream out("output.txt");
int main()
{
    int i=9,r=1,n;
    in >> n;
    if (!n)
        out << "10";
    else if (n==1)
        out << "1";
    else
    {
        while (n>1 && i>1)
        {
            while (n>1 && n%i==0)
            {
                n/=i;
                s+=i+'0';
            }
            i--;
        }
        sort(s.begin(),s.end());
        if (n!=1)
            out << "-1";
        else
            out << s;
    }
    return 0;
}
