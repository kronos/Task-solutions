#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int main()
{
    unsigned long long int A;
    in >> A;
    out << A*A;
    return 0;
}
