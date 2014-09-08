#include <istream.h>
#include <stdio.h>
int main()
{
  char *s;
  s = new char[1000];
  gets(s);
  int i,c;
  i = 0;
  int k=0;
  while (s[k])
  {
    c = s[k]-48;
    if (i==0)
      i+=c;
    else if (i<10)
        i=i*10+c;
       else if (i<100)
          i=i*10+c;
    if (i>6)
      i = i%7;
    k++;
  }
  printf("%d",i);
  delete[] s;
  return 0;
}
