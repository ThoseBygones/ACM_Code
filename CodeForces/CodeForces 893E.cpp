#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000005    //开两倍1e6否则会wa24
#define LL long long
#define MOD 1000000007
#define PB push_back

//非递归版
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

/*线性预处理逆元*/
LL inv[MAXN];
LL res[MAXN];
LL fac[MAXN];

void initInv()
{
    inv[1] = 1;
    fac[1] = 1;
    res[1] = 1;
    for(int i = 2; i<MAXN; i++)
    {
        inv[i] = 1LL * MOD / i * (MOD - inv[MOD % i]) % MOD;
        res[i] = (inv[i] * res[i - 1]) % MOD;
        fac[i] = 1LL * (fac[i - 1] * i) % MOD;
    }
}

LL C(int n, int m)  //求组合数C(n,m)
{
    if (m == 0 || m == n)
        return 1;
    return fac[n] * res[n - m] % MOD * res[m] % MOD;
}

vector <int> v;

int main()
{
    initInv();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v.clear();
        LL ans=1;
        int temp=x;
        for(int i=2; i*i<=temp; i++)   //分解质因数
        {
            if(x%i==0)
            {
                int cnt=0;
                while(x%i==0)
                {
                    cnt++;
                    x/=i;
                }
                v.PB(cnt);
            }
        }
        if(x>1) //记下剩余的值
            v.PB(1);
        for(int i=0; i<v.size(); i++)   //转化成盒子放球模型，y+k-1个空位放y-1个挡板（允许挡板相邻）
            ans=(ans*C(v[i]+y-1,y-1))%MOD;
        ans=(ans*quickPow(2,y-1,MOD))%MOD; //C(y,0)+C(y,2)+C(y,4)+...
        printf("%I64d\n",ans);
    }
    return 0;
}
