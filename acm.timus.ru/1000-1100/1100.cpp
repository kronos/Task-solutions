#include <iostream>
//#include <cmath>
#include <string>
#include <map>
#include <vector>
using namespace std;
string s;
map<int, vector<int> >  t;
map<int, vector<int> >::reverse_iterator it;
int N,i,id,p;
int main()
{
   cin >> N;
   for(i=0;i<N;i++)
   {
      cin >> id >> p;
      t[p].push_back(id);
   }
   for(it=t.rbegin();it!=t.rend();it++)
   {
      for(i=0;i<it->second.size();i++)
      {
   cout << it->second[i] << " " << it->first << endl;
      }
   }
   return 0;
}
