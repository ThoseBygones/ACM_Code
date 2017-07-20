/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Matrix
{
    int a[5][5];
} mat[5];

int n,m;

void init()
{
    mat[0].a[1][1]=1;
    mat[0].a[1][2]=1;
    mat[0].a[2][1]=1;
    mat[0].a[2][2]=2;
}

void mul(int x,int y,int z)
{
    for(int i=1; i<=2; i++)
    {
        for(int j=1; j<=2; j++)
        {
            mat[2].a[i][j]=0;
            for(int k=1; k<=2; k++)
                mat[2].a[i][j]=(mat[2].a[i][j]+mat[y].a[i][k]*mat[z].a[k][j])%m;
        }
    }
    mat[x]=mat[2];
}

void getUnitMatrix()
{
    memset(mat[1].a,0,sizeof(mat[1].a));
    for(int i=1; i<=2; i++)
        mat[1].a[i][i]=1;
}

void quickPow(int b)
{
    getUnitMatrix();
    while(b)
    {
        if(b&1)
            mul(1,0,1);
        mul(0,0,0);
        b>>=1;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        quickPow(n);
        printf("%d\n",mat[1].a[1][2]);
    }
    return 0;
}
*/


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
    printf("%lld\n",a.x[1][0]);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL k,m;
        scanf("%lld%lld",&k,&m);
        n=2;
        mod=m;
        A.x[0][0]=2;
        A.x[0][1]=1;
        A.x[1][0]=1;
        A.x[1][1]=1;
        A=pow(A,k);
        print(A);
    }
    return 0;
}
