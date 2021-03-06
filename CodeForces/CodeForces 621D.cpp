#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
using namespace std;

long double a[15],x,y,z;
string algo[]= {" ","x^y^z","x^z^y","(x^y)^z","(x^z)^y","y^x^z","y^z^x","(y^x)^z","(y^z)^x","z^x^y","z^y^x","(z^x)^y","(z^y)^x"};

int main()
{
    while(cin>>x>>y>>z)
    {
        int i,p=1;
        a[1]=pow(y,z)*log(x);
        a[2]=pow(z,y)*log(x);
        a[3]=y*z*log(x);
        a[4]=a[3];
        a[5]=pow(x,z)*log(y);
        a[6]=pow(z,x)*log(y);
        a[7]=x*z*log(y);
        a[8]=a[7];
        a[9]=pow(x,y)*log(z);
        a[10]=pow(y,x)*log(z);
        a[11]=x*y*log(z);
        a[12]=a[11];
        long double m=a[1];
        for(i=2; i<13; i++)
        {
            if(m<a[i])
            {
                m=a[i];
                p=i;
            }
        }
        cout<<algo[p]<<endl;
    }
    return 0;
}
