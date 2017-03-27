#include <string>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int ff[8][8],fi,fj,li,lj,ki,kj,i,j,ii,jj,r;
string f,l,k;
int main()
{
   in >> f >> l >> k;
   fi = f[1]-'1';
   fj = f[0]-'A';

   li = l[1]-'1';
   lj = l[0]-'A';

   ki = k[1]-'1';
   kj = k[0]-'A';
   for(i=0;i<8;i++)
      ff[fi][i] = ff[li][i] = ff[i][fj] = ff[i][lj] = 1;

   if (ki>1)
   {
      if (kj>0) ff[ki-2][kj-1] = 1;
      if (kj<7) ff[ki-2][kj+1] = 1;
   }

   if (ki<6)
   {
      if (kj>0) ff[ki+2][kj-1] = 1;
      if (kj<7) ff[ki+2][kj+1] = 1;
   }

   if (kj>1)
   {
      if (ki>0) ff[ki-1][kj-2] = 1;
      if (ki<7) ff[ki+1][kj-2] = 1;
   }

   if (kj<6)
   {
      if (ki>0) ff[ki-1][kj+2] = 1;
      if (ki<7) ff[ki+1][kj+2] = 1;
   }
   ii = fi; jj=fj;
   while (ii>=0 && jj>=0)
   {
      ff[ii][jj] = 1;
      ii--;jj--;
   }
   ii = fi; jj=fj;
   while (ii<8 && jj<8)
   {
      ff[ii][jj] = 1;
      ii++;jj++;
   }

   ii = fi; jj=fj;
   while (ii>=0 && jj<8)
   {
      ff[ii][jj] = 1;
      ii--;jj++;
   }

   ii = fi; jj=fj;
   while (ii<8 && jj>=0)
   {
      ff[ii][jj] = 1;
      ii++;jj--;
   }

   ff[fi][fj] = ff[ki][kj] = ff[li][lj] = 0;
   for(i=0;i<8;i++)
      for(j=0;j<8;j++)
     r+=ff[i][j];
   out << r;
   return 0;
}
