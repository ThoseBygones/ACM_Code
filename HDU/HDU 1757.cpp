#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define LL long long
#define MAXN 15
#define INF 0x3f3f3f3f
#define MOD 1000000007

typedef LL Type;

int n;
Type mod;

struct Matrix   //矩阵的类
{
    Type x[MAXN][MAXN];
    void init() //将其初始化为单位矩阵
    {
        memset(x,0,sizeof(x));
        for(int i=0; i<n; i++)
            x[i][i]=1;
    }
} A,U;

Matrix mul(Matrix a,Matrix b)   //(a*b)%mod 矩阵乘法
{
    Matrix ans;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            ans.x[i][j]=0;
            for(int k=0; k<n; k++)
                ans.x[i][j]+=a.x[i][k]*b.x[k][j];
            ans.x[i][j]%=mod;
        }
    }
    return ans;
}

Matrix add(Matrix a,Matrix b)   //(a+b)%mod 矩阵加法
{
    int i,j;
    Matrix ans;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            ans.x[i][j]=a.x[i][j]+b.x[i][j];
            ans.x[i][j]%=mod;
        }
    }
    return ans;
}

Matrix pow(Matrix a,Type k)  //(a^n)%mod 矩阵快速幂
{
    Matrix ans;
    ans.init();
    while(k)
    {
        if(k&1) //k%2
            ans=mul(ans,a);
        k/=2;
        a=mul(a,a);
    }
    return ans;
}

Matrix sum(Matrix a,Type k)  //(a+a^2+a^3....+a^n)%mod 矩阵的幂和
{
    Type m;
    Matrix ans,pre;
    if(k==1)
        return a;
    m=k/2;
    pre=sum(a,m);   //[1,n/2]
    ans=add(pre,mul(pre,pow(a,m))); //ans=[1,n/2]+a^(n/2)*[1,n/2]
    if(n&1)
        ans=add(ans,pow(a,k));  //ans=ans+a^n
    return ans;
}

void print(Matrix a)    //输出矩阵
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            printf("%lld%c",a.x[i][j],j==n-1?'\n':' ');
}

int main()
{
    LL k,m;
    while(~scanf("%lld%lld",&k,&m))
    {
        n=10;
        mod=m;
        for(int i=0;i<10;i++)
            A.x[i][i-1]=1;
        for(int i=0; i<10; i++)
            scanf("%lld",&A.x[0][i]);
        if(k<10)
            printf("%lld\n",k%mod);
        Matrix B=pow(A,k-9);
        LL ans=0;
        for(int i=0;i<10;i++)
            ans+=(B.x[0][i]*(9-i))%mod;
        printf("%lld\n",ans%mod);
    }
    return 0;
}
