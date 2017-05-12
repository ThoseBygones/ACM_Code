#include <bits/stdc++.h>
#define LL long long
using namespace std;

bool isPrime(LL x)
{
    for(LL i=2; i*i<=x; i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

int main()
{
    LL n;
    cin >> n;
    int ans=0;
    if(isPrime(n))
        ans=1;
    else
    {
        if(n%2==0)
            ans=2;
        else
        {
            if(isPrime(n-2))
                ans=2;
            else
                ans=3;
        }
    }
    cout << ans << endl;
    return 0;
}
