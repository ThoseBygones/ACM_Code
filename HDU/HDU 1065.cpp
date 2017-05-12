#include<iostream>
#include<cmath>
using namespace std;

#define PI 3.1415926

int main()
{
    int n,year;
    double x,y,r,s;
    while(cin >> n)
    {
        for(int i=1; i<=n; i++)
        {
            cin >> x >> y;
            r=sqrt(x*x+y*y);
            s=PI*r*r/2;
            year=s/50;
            cout << "Property " << i << ": This property will begin eroding in year " << year+1 << "." << endl;
        }
        cout << "END OF OUTPUT." << endl;
    }
    return 0;
}
