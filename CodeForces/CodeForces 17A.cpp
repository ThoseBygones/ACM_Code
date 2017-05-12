#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 1005
using namespace std;

bool isPrime(int x)
{
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

int main()
{
    int prime[MAXN],noldbach[MAXN];
    int ai=1,bi=0;
    prime[0]=2;
    for(int i=3; i<=1000; i++)
    {
        if(isPrime(i))
        {
            prime[ai++]=i;
            noldbach[bi++]=prime[ai-1]+prime[ai-2]+1;
        }
    }
    int n,k;
    while(cin >> n >> k)
    {
        int cnt=0;
        for(int i=2; i<=n; i++)
        {
            if(isPrime(i) && find(noldbach,noldbach+bi,i)!=noldbach+bi)
                cnt++;
        }
        if(cnt>=k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
