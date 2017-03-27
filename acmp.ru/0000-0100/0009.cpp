#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int N;
vector<int> nums;
int main()
{
   in >> N;
   int i,t,s=0;
   for(i=0;i<N;i++)
   {
      in >> t;
      if (t>0)
     s+=t;
      nums.push_back(t);
   }
   int imin=0,imax=0;
   for(i=1;i<N;i++)
   {
      if (nums[i]<nums[imin])
     imin = i;
      if (nums[i]>nums[imax])
     imax = i;
   }

   int p = 1;
   for(i=min(imin,imax)+1;i<max(imin,imax);i++)
      p*=nums[i];
   out << s << " " << p;
   return 0;
}
