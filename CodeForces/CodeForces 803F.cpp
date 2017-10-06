#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define LL long long
#define MOD 1000000007

LL fac[MAXN];
LL dp[MAXN];    //dp[i]表示gcd==i的子序列数量

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

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        int temp;
        scanf("%d",&temp);
        for(int j=1; j*j<=temp; j++)
        {
            if(temp%j==0)
            {
                fac[j]++;
                if(j!=temp/j)
                    fac[temp/j]++;
            }
        }
    }
    for(int i=1; i<=100000; i++)
        dp[i]=quickPow(2,fac[i],MOD)-1;
    for(int i=100000; i; i--)
    {
        for(int j=i+i; j<=100000; j+=i)
            dp[i]=(dp[i]-dp[j]+MOD)%MOD;    //容斥原理
    }
    printf("%I64d\n",dp[1]);
    return 0;
}
