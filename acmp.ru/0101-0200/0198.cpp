#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;
double a[100][101];
double x[100];
int n;

void MethodGaussa()
{
    double t;

    int n_rows = n;
    int n_columns = n+1;
    int ii,jj;
    for (int i = 0; i < n_rows - 1; i++)
    {
        t = a[i][i];
        if (t == 0.0)
        {
            ii = i+1;
            while (a[ii][i]==0.0)
                ii++;
            for (jj=0;jj<=n;jj++)
            {
                t = a[i][jj];
                a[i][jj] = a[ii][jj];
                a[ii][jj] = t;
            }
        }
        t = a[i][i];
        for (int k = 0; k < n_columns; k++)
        {
            a[i][k] = a[i][k] / t;
        }
        for (int n = i+1; n < n_rows; n++)
        {
            t = a[n][i];
            for (int j = 0; j < n_columns; j++)
            {
                a[n][j] = a[n][j] - t * a[i][j];
            }
        }
    }

    x[n-1] = a[n-1][n] / a[n-1][n-1];
    double sum;
    for (int i = n-2; i >= 0; i--)
    {
        sum = 0;
        for (int k = i+1; k < n; k++)
            sum += (a[i][k] * x[k]) ;
        x[i] = (a[i][n]-sum)/a[i][i];
    }

}

int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    int i,j;
    cin >> n;
    for (i=0;i<n;i++)
        for (j=0;j<=n;j++)
            cin >> a[i][j];

    MethodGaussa();
    for (i = 0; i < n; i++)
    {
        if (x[i]<-0.49)
            printf("%d ",(int)(x[i]-0.5));
        else
            printf("%d ",(int)(x[i]+0.5));
    }

    return 0;
}
