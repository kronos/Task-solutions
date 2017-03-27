#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int main()
{
    int A,B;
    in >> A >> B;
    out << A+B;
    return 0;
}
