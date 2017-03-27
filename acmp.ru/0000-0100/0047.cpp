#include <cmath>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

struct divv
{
  int s;
  int l;
  int c;
  divv() {
     s = 0;
     l = 0;
     c = 0;
  }

  divv(int i) {
    c = i;
    l = 0;
    s = 0;

    while(i > 0) {
      s+= i%10;
      i/= 10;
      l++;
    }
  }

  bool operator > (const divv &r)
  {
     if (s==r.s)
       return l < r.l;
     else
       return s > r.s;
  }
};

divv c(1);

int main()
{

   int n;
   in >> n;
   for(int i = 2; i <= n/2+1; i++) {
      if (n%i == 0) {
        divv p(i);
        if (p > c)
          c = p;
      }
   }
   divv p(n);

   if (p > c)
      out << p.c;
   else
      out << c.c;

   return 0;
}
