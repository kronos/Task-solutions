#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int main()
{
    double x1,y1,x2,y2;
    double r1,r2,r;
    in >> x1 >> y1 >> r1;
    in >> x2 >> y2 >> r2;
    r = sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
    //cout << r1 << " " << r2 << " " << r << " " << endl;
    double mi = min(r1,r2);
    double ma = max(r1,r2);
    if (r1+r2<r || ma>mi+r || (x1==x2 && y1==y2 && r1 ==r2 ))
      out << "NO";
    else
      out << "YES";
    return 0;
}
