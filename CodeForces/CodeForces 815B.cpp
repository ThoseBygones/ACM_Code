#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f
#define LL long long
#define MOD 1000000007

LL inv[MAXN];
LL res[MAXN];
LL fac[MAXN];
LL a[MAXN];

LL C(LL n, LL m)
{
    if (m == 0 || m == n)
        return 1;
    return fac[n]*res[n-m]%MOD*res[m]%MOD;
}

void init()
{
    //线性预处理逆元
    inv[1] = 1;
    fac[1] = 1;
    res[1] = 1;
    for(int i = 2; i<MAXN; i++)
    {
        inv[i] = 1LL*MOD/i*(MOD-inv[MOD%i])%MOD;
        res[i] = (inv[i]*res[i-1])%MOD;
        fac[i] = 1LL*(fac[i-1]*i)%MOD;
    }
}

int main()
{
    init();
    //for(int i=1; i<=10; i++)
    //    cout << res[i] << endl;
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    if(n==1)
        cout << a[1] << endl;
    else if(n==2)
        cout << (a[1]+a[2])%MOD << endl;
    else
    {
        LL cnt=0;
        if(n&1)
        {
            for(int i=1; i<n; i++)
            {
                if(cnt&1)
                    a[i]-=a[i+1];
                else
                    a[i]+=a[i+1];
                cnt++;
                a[i]=(a[i]+MOD)%MOD;
            }
            n--;
        }
        LL ans=0;
        LL op=(n%4==0?-1:1);
        for(int i=1; i<=n; i+=2)
        {
            ans+=C((n-2)/2,i/2)*(a[i]+op*a[i+1])%MOD;
            ans%=MOD;
        }
        ans=(ans+MOD)%MOD;
        cout << ans << endl;
    }
    return 0;
}
