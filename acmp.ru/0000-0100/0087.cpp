#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
string s,p;
ifstream in("input.txt");
ofstream out("output.txt");
vector<string> l;
map<string,int> d,q;
int main()
{
    in >> s;
    while(s!="ENDOFINPUT")
    {
        l.push_back(s);
        d[s]++;
        in >> s;
    }
    int i,j;
    unsigned long long int r=0;
    for (i=0;i<l.size();i++)
        for (j=i;j<l.size();j++)
        {
            p = l[i]+l[j];
            if (d.find(p)!=d.end() && q.find(p)==q.end())
            {
                r+=d[p];
                q[p] = true;
            }
            if (i!=j)
            {
                p = l[j]+l[i];
                if (d.find(p)!=d.end() && q.find(p)==q.end())
                {
                    r+=d[p];
                    q[p] = true;
                }
            }
        }
    out << r;
    return 0;
}
