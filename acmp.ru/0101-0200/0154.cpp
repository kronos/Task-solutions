#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
double N,N1,N2,N3,N4,N5,N6,N7,N8;
int i1,i2,i3,i4,i5,i6,i7,i8;
int q1,q2,q3,q4,q5,q6,q7,q8;
bool f;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    cin >> N;
    for(i1=pow(N,1/3.0);i1>=1;i1--)
    {
        q1 = i1*i1*i1;
        if (q1!=N)
        {
            N1 = N-q1;
            for(i2=pow(N1,1/3.0);i2>=1;i2--)
            {
                q2 = i2*i2*i2;
                if (q2!=N1)
                {
                    N2 = N1-q2;
                    for(i3=pow(N2,1/3.0);i3>=1;i3--)
                    {
                        q3 = i3*i3*i3;
                        if (q3!=N2)
                        {
                            N3 = N2-q3;
                            for(i4=pow(N3,1/3.0);i4>=1;i4--)
                            {
                                q4 = i4*i4*i4;
                                if (q4!=N3)
                                {
                                    N4 = N3-q4;
                                    for(i5=pow(N4,1/3.0);i5>=1;i5--)
                                    {
                                        q5 = i5*i5*i5;
                                        if (q5!=N4)
                                        {
                                            N5 = N4-q5;
                                            for(i6=pow(N5,1/3.0);i6>=1;i6--)
                                            {
                                                q6 = i6*i6*i6;
                                                if (q6!=N5)
                                                {
                                                    N6 = N5-q6;
                                                    for(i7=pow(N6,1/3.0);i7>=1;i7--)
                                                    {
                                                        q7 = i7*i7*i7;
                                                        if (q7!=N6)
                                                        {
                                                            N7 = N6-q7;
                                                            for(i8=pow(N7,1/3.0);i8>=1;i8--)
                                                            {
                                                                q8 = i8*i8*i8;
                                                                if (q8!=N7)
                                                                {
                                                                    break;
                                                                }
                                                                else
                                                                {
                                                                    cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << " " << i6 << " " << i7 << " " << i8;
                                                                    return 0;
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << " " << i6 << " " << i7;
                                                            return 0;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << " " << i6;
                                                    return 0;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5;
                                            return 0;
                                        }
                                    }
                                }
                                else
                                {
                                    cout << i1 << " " << i2 << " " << i3 << " " << i4;
                                    return 0;
                                }
                            }
                        }
                        else
                        {
                            cout << i1 << " " << i2 << " " << i3;
                            return 0;
                        }
                    }
                }
                else
                {
                    cout << i1 << " " << i2;
                    return 0;
                }
            }
        }
        else
        {
            cout << i1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
