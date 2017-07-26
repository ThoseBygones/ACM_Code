//dp：用dp[N][4]来表示N块砖块的染色情况，一共有四种状态。
//dp[N][0] ：表示N块中红色绿色的数量均为偶数。
//dp[N][1] ：表示N块中红色为偶数，绿色为奇数。
//dp[N][2] ：表示N块中红色为奇数，绿色为偶数。
//dp[N][3] ：表示N块中红色绿色的数量均为奇数。
//状态转移方程为：
//dp[N+1][0] = 2 * dp[N][0] + 1 * dp[N][1] + 1 * dp[N][2] + 0 * dp[N][3]；
    //1.若现在红色绿色均为偶数，想下一步维持现状，第i+1块涂上蓝色或黄色即可（2种方案）
    //2.若现在红色偶数块绿色奇数块，想下一步让他们数量都变成偶数块，第i+1块涂上绿色即可（1种方案）
    //3.若现在红色奇数块绿色偶数块，想下一步让他们数量都变成偶数块，第i+1块涂上红色即可（1种方案）
    //4.若现在红色绿色均为奇数，想下一步让他们数量都变成偶数块，无解（0种方案））
//dp[N+1][1] = 1 * dp[N][0] + 2 * dp[N][1] + 0 * dp[N][2] + 1 * dp[N][3]
    //1.若现在红色绿色均为偶数，想下一步变成红色偶数块绿色奇数块，第i+1块涂上绿色即可（1种方案）
    //2.若现在红色偶数块绿色奇数块，想下一步变成红色偶数块绿色奇数块，无解（0种方案）
    //3.若现在红色奇数块绿色偶数块，想下一步维持现状，第i+1块涂上蓝色或黄色即可（2种方案）
    //4.若现在红色绿色均为奇数，想下一步变成红色偶数块绿色奇数块，第i+1块涂上红色即可（1种方案）
//dp[N+1][2] = 1 * dp[N][0] + 0 * dp[N][1] + 2 * dp[N][2] + 1 * dp[N][3]
    //1.若现在红色绿色均为偶数，想下一步变成红色奇数块绿色偶数块，第i+1块涂上红色即可（1种方案）
    //2.若现在红色偶数块绿色奇数块，想下一步维持现状，第i+1块涂上蓝色或黄色即可（2种方案）
    //3.若现在红色奇数块绿色偶数块，想下一步变成红色偶数块绿色奇数块，无解（0种方案）
    //4.若现在红色绿色均为奇数，想下一步变成红色奇数块绿色偶数块，第i+1块涂上绿色即可（1种方案）
//dp[N+1][3] = 0 * dp[N][0] + 1 * dp[N][1] + 1 * dp[N][2] + 2 * dp[N][3]
    //1.若现在红色绿色均为偶数，想下一步让他们的数量都变成奇数块，无解（0种方案）
    //2.若现在红色偶数块绿色奇数块，想下一步让他们数量都变成奇数块，第i+1块涂上红色即可（1种方案）
    //3.若现在红色奇数块绿色偶数块，想下一步让他们数量都变成奇数块，第i+1块涂上绿色即可（1种方案）
    //4.若现在红色绿色均为偶数，想下一步维持现状，第i+1块涂上黄色或蓝色即可（2种方案）
/*构造矩阵：
| 2 1 1 0 |
| 1 2 0 1 |
| 1 0 2 1 |
| 0 1 1 2 |
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5
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
    mod=10007;
    n=4;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL k;
        scanf("%lld",&k);
        A.x[0][0]=2, A.x[0][1]=1, A.x[0][2]=1, A.x[0][3]=0;
        A.x[1][0]=1, A.x[1][1]=2, A.x[1][2]=0, A.x[1][3]=1;
        A.x[2][0]=1, A.x[2][1]=0, A.x[2][2]=2, A.x[2][3]=1;
        A.x[3][0]=0, A.x[3][1]=1, A.x[3][2]=1, A.x[3][3]=2;
        Matrix ans=pow(A,k);
        printf("%d\n",ans.x[0][0]);
    }
    return 0;
}
