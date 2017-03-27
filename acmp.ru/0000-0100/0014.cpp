#include <cmath>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int del[46341];
int del2[46341];
int main()
{
   int n1,n2,i;
   in >> n1 >> n2;
   i = 2;
   while(n1 != 1) {
      while ( n1%i !=0) {
       i++;
      }
      do {
        del[i]++;
        n1/=i;
      } while(n1 > 1 && n1%i == 0);
   }

   i = 2;
   while(n2 != 1) {
      while (n2%i!=0) {
       i++;
      }
      do {
        del2[i]++;
        n2/=i;
      } while(n2 > 1 && n2%i == 0);
   }

   int r = 1;

   for(i = 0; i < 46341; i++) {
      if (del[i] || del2[i]) {
        if (del2[i] > del[i]) {
          r*= powf(i, del[i] + abs(del2[i] - del[i]));
        } else {
          r*= powf(i, del[i]);
        }
      }
   }

   if (r != 1)
      out << r;
   else
      out << n1;

   return 0;
}
