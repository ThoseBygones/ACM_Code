//枚举每行的状态，不过六种：
//（会受上一行影响，0表示空缺，1表示被占）
//a. 0 0 0 0
//b. 1 1 1 1
//c. 1 0 0 1
//d. 0 0 1 1
//e. 1 1 0 0
//f. 0 1 1 0
//状态转移方程如下：
//a[i] = a[i-1] + b[i-1] + c[i-1] + d[i-1] + e[i-1];
//b[i] = a[i-1];
//c[i] = a[i-1] + f[i-1];
//d[i] = a[i-1] + e[i-1];
//e[i] = a[i-1] + d[i-1];
//f[i] = c[i-1];
//故可构造矩阵：
/*
| 1 1 1 1 1 0 |
| 1 0 0 0 0 0 |
| 1 0 0 0 0 1 |
| 1 0 0 0 1 0 |
| 1 0 0 1 0 0 |
| 0 0 1 0 0 0 |
*/
//矩阵快速幂
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 55
#define LL long long
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
    n=6;
    while(~scanf("%lld%lld",&k,&m))
    {
        if(k==0 && m==0)
            break;
        mod=m;
        A.x[0][0]=1,A.x[0][1]=1,A.x[0][2]=1,A.x[0][3]=1,A.x[0][4]=1,A.x[0][5]=0;
        A.x[1][0]=1,A.x[1][1]=0,A.x[1][2]=0,A.x[1][3]=0,A.x[1][4]=0,A.x[1][5]=0;
        A.x[2][0]=1,A.x[2][1]=0,A.x[2][2]=0,A.x[2][3]=0,A.x[2][4]=0,A.x[2][5]=1;
        A.x[3][0]=1,A.x[3][1]=0,A.x[3][2]=0,A.x[3][3]=0,A.x[3][4]=1,A.x[3][5]=0;
        A.x[4][0]=1,A.x[4][1]=0,A.x[4][2]=0,A.x[4][3]=1,A.x[4][4]=0,A.x[4][5]=0;
        A.x[5][0]=0,A.x[5][1]=0,A.x[5][2]=1,A.x[5][3]=0,A.x[5][4]=0,A.x[5][5]=0;
        Matrix ans=pow(A,k);
        printf("%lld\n",ans.x[0][0]);
    }
    return 0;
}
