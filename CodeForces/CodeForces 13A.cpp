#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a%b == 0)
        return b;
    return gcd(b,a%b);
}

int main()
{
    int x;
    while(cin >> x)
    {
        int sum=0;
        int temp;
        for(int i=2; i<x; i++)
        {
            int dr=0;
            temp=x;
            while(temp)
            {
                dr+=temp%i;
                temp/=i;
            }
            sum+=dr;
        }
        cout << sum/gcd(sum,x-2) << "/" << (x-2)/gcd(sum,x-2) << endl;
    }
    return 0;
}
