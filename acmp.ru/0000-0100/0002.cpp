#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
    long long int A, B = 0;
    in >> A;

    if (A > 0)
     out << ((1 + A) * A) / 2;
    else
     out << ((1 + A) * (labs(A) + 2))/2;

    return 0;
}
