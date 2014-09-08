#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int main() {
  double x;
  cout.setf(ios::fixed);
  cout.precision(4);
  stack<double> st;

  while(cin >> x) {
    st.push(sqrt(x));
  }

  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}
