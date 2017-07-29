//快速幂+前缀和
#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define LL long long
#define MOD 1000000007

LL a[MAXN];
LL sum[MAXN];

LL quickPow(LL x,LL k,LL mod)
{
    LL res = 1;
    while(k > 0)
    {
        if(k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    LL ans=0;
    for(int i=1; i<=n; i++)
        sum[i]=(sum[i-1]+a[i])%MOD;
    for(int i=1; i<n; i++)
    {
        LL temp=sum[n]-sum[i]-sum[n-i];
        temp%=MOD;
        if(temp<0)
            temp=(temp+MOD)%MOD;
        ans=(ans+quickPow(2,i-1,MOD)*temp%MOD)%MOD;
    }
    cout << ans << endl;
}
