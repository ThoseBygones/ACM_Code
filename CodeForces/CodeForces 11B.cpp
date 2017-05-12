#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,x;
    while(cin >> x)
    {
        x=abs(x);
        for(n=0; ; n++)
        {
            int l=n*(n+1)/2;
            if(l==x)
                break;
            else if(l>x)
            {
                if((l-x)%2==0)
                    break;
            }
        }
        cout << n << endl;
    }
    return 0;
}
