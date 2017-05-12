#include<iostream>
using namespace std;

int gcd(int x,int y)
{
    if(x%y==0)
        return y;
    else
        return gcd(y,x-y);
}

int main()
{
    int a,b,c;
    while(cin >> a >> b)
    {
        int cnt=0;
        c=max(a,b);
        for(int i=c; i<=6; i++)
            cnt++;
        if(cnt==0)
            cout << "0/1" << endl;
        else if(cnt==6)
            cout << "1/1" << endl;
        else
        {
            int d=gcd(6,cnt);
            cout << cnt/d << "/" << 6/d << endl;
        }
    }
    return 0;
}
