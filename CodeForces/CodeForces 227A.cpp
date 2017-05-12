#include <iostream>
#define LL long long
using namespace std;

LL xa,ya,xb,yb,xc,yc;

int main()
{
    while(cin >> xa >> ya >> xb >> yb >> xc >> yc)
    {
        LL sum=xa*(yb-yc)-ya*(xb-xc)+xb*yc-xc*yb;
        if(sum==0)
            cout << "TOWARDS" << endl;
        else if(sum<0)
            cout << "RIGHT" << endl;
        else
            cout << "LEFT" << endl;
    }
    return 0;
}
