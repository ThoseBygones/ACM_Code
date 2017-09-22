//概率dp+矩阵快速幂优化求概率
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//dp[i]表示走到i位置的概率。可以算出走到每个地雷的概率，则最后能安全通过雷区的概率为不走到每个地雷的概率乘积
//dp[i]=p*dp[i-1]+(1-p)*dp[i-2]
//数据范围太大，用矩阵快速幂优化

#define MAXN 5
#define MOD 1000000007

typedef double Type;

int n;
int mine[MAXN];

struct Matrix   //矩阵的类
{
    Type x[MAXN][MAXN];
    void init() //将其初始化为单位矩阵
    {
        memset(x,0,sizeof(x));
        for(int i=0; i<n; i++)
            x[i][i]=1;
    }
} A;

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
            //ans.x[i][j]%=mod;
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
            //ans.x[i][j]%=mod;
        }
    }
    return ans;
}

Matrix pow(Matrix a,int k)  //(a^n)%mod 矩阵快速幂
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

Matrix sum(Matrix a,int k)  //(a+a^2+a^3....+a^n)%mod 矩阵的幂和
{
    int m;
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
    n=2;
    int m;
    double p;
    while(~scanf("%d%lf",&m,&p))
    {
        mine[0]=0;
        for(int i=1; i<=m; i++)
            scanf("%d",&mine[i]);
        sort(mine,mine+m+1);
        double ans=1.0;
        A.x[0][0]=p;
        A.x[0][1]=1.0-p;
        A.x[1][0]=1.0;
        A.x[1][1]=0.0;
        for(int i=1; i<=m; i++)
        {
            Matrix res=pow(A,mine[i]-mine[i-1]-1);
            ans*=(1-res.x[0][0]);
        }
        printf("%.7f\n",ans);
    }
    return 0;
}
