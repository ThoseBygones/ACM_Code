#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define LL long long
#define MOD 1000000007

typedef LL Type;

int n;
//Type mod;

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
    memset(ans.x,0,sizeof(ans.x));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a.x[i][j])   //稀疏矩阵，加速优化（不加这个判断TLE）
            {
                for(int k=0; k<n; k++)
                {
                    ans.x[i][k]+=a.x[i][j]*b.x[j][k];
                    //ans.x[i][j]%=mod;
                }
            }
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
    LL m;
    int k;
    //mod=1;
    while(~scanf("%d%lld%d",&n,&m,&k))
    {
        if(n==0 && m==0 && k==0)
            break;
        n++;
        A.init();
        while(k--)
        {
            char op[2];
            scanf("%s",op);
            if(op[0]=='g')  //加花生米操作
            {
                int p;
                scanf("%d",&p);
                A.x[0][p]++;
            }
            if(op[0]=='e')  //吃花生米操作
            {
                int p;
                scanf("%d",&p);
                for(int i=0; i<n; i++)
                    A.x[i][p]=0;
            }
            if(op[0]=='s')  //交换花生米操作
            {
                int p,q;
                scanf("%d%d",&p,&q);
                for(int i=0; i<n; i++)
                    swap(A.x[i][p],A.x[i][q]);
            }
        }
        Matrix ans=pow(A,m);
        //print(ans);
        for(int i=1; i<n-1; i++)
            printf("%lld ",ans.x[0][i]);
        printf("%lld\n",ans.x[0][n-1]);
    }
    return 0;
}
