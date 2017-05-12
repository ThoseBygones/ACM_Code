#include<iostream>
using namespace std;

int apple(int m,int n)
{
    if(m==1 || n==1)
        return 1;
    else if(m==n)
        return apple(m,n-1)+1;
    else if(n>m)
        return apple(m,m);
    else
        return apple(m,n-1)+apple(m-n,n);
}

int main()
{
    int t,m,n;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        cout << apple(m,n) << endl;
    }
    return 0;
}
