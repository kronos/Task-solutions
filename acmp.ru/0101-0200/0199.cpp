#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;
map<char,int> d1;
bool error;
int romantodecimal(string rom)
{
    if (rom=="O" || rom=="o")
        return 0;
    d1['I'] = 0;
    d1['V'] = 0;
    d1['X'] = 0;
    d1['L'] = 0;
    d1['C'] = 0;
    d1['D'] = 0;
    d1['M'] = 0;
    char n;
    long long int r=0;
    for (int i=0;i<rom.length();i++)
    {
        n = rom[i];
        switch(n)
        {
        case 'I':
            d1[n]+=1;
            break;
        case 'V':
            d1[n]+=5-d1['I'];
            d1['I'] = 0;
            break;
        case 'X':
            d1[n]+=10-d1['I']-d1['V'];
            d1['I'] = 0;
            d1['V'] = 0;
            break;
        case 'L':
            d1[n]+=50-d1['I']-d1['V']-d1['X'];
            d1['I'] = 0;
            d1['V'] = 0;
            d1['X'] = 0;
            break;
        case 'C':
            d1[n]+=100-d1['I']-d1['V']-d1['X']-d1['L'];
            d1['I'] = 0;
            d1['V'] = 0;
            d1['X'] = 0;
            d1['L'] = 0;
            break;
        case 'D':
            d1[n]+=500-d1['I']-d1['V']-d1['X']-d1['L']-d1['C'];
            d1['I'] = 0;
            d1['V'] = 0;
            d1['X'] = 0;
            d1['L'] = 0;
            d1['C'] = 0;
            break;
        case 'M':
            d1[n]+=1000-d1['I']-d1['V']-d1['X']-d1['L']-d1['C']-d1['D'];
            d1['I'] = 0;
            d1['V'] = 0;
            d1['X'] = 0;
            d1['L'] = 0;
            d1['C'] = 0;
            d1['D'] = 0;
            break;
        default:
            error = true;
            return 0;
        break;
        }
        r = d1['I']+d1['V']+d1['X']+d1['L']+d1['C']+d1['D']+d1['M'];
    }
    /*if (r>10000)
    {
    flag = true;
    return 0;
    }*/
    return r;
}


string decimaltoroman(int value)
{
    if (value==0)
        return "O";
    string rom = "";
    while(value!=0)
        if (value >= 1000)
        {
            value-=1000;
            rom += 'M';
        }
        else if(value >= 900)
        {
            value-=900;
            rom += "CM";
        }
        else if(value >= 500)
        {
            value-=500;
            rom += 'D';
        }
        else if(value >= 400)
        {
            value-=400;
            rom += "CD";
        }
        else if(value >= 100)
        {
            value-=100;
            rom +='C';
        }
        else if(value >= 90)
        {
            value-=90;
            rom += "XC";
        }
        else if(value >= 50)
        {
            value-=50;
            rom += "L";
        }
        else if(value >= 40)
        {
            value-=40;
            rom += "XL";
        }
        else if(value >= 10)
        {
            value-=10;
            rom += 'X';
        }
        else if(value >= 9)
        {
            value-= 9;
            rom += "IX";
        }
        else if(value >= 5)
        {
            value-=5;
            rom += 'V';
        }
        else if(value >= 4)
        {
            value-=4;
            rom += "IV";
        }
        else if(value >= 1)
        {
            value-=1;
            rom += 'I';
        };
        return rom;
}

int NOD(int a, int b)
{
    while (a!=b)
    {
        if (a>b)
            a-=b;
        else
            b-=a;
    }
    return a;
}
int main()
{
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    string s,s1,s2;
    cin >> s;
    int n1,n2,i;
    int q= s.find('/');
    if (q==string::npos || q==0 || q==s.length()-1)
    {
        cout << "ERROR";
        return 0;
    }
    s1 = s.substr(0,q);
    s2 = s.substr(q+1,s.length()-q);
    n1 = romantodecimal(s1);
    n2 = romantodecimal(s2);

    if (error)
    {
        cout << "ERROR";
        return 0;
    }

    if (n1%n2==0)
    {
        n1/=n2;
        cout << decimaltoroman(n1);
    }
    else
    {
        int q = NOD(n1,n2);
        n1/= q;
        n2/= q;
        cout << decimaltoroman(n1) << '/' << decimaltoroman(n2);
    }
    return 0;
}
