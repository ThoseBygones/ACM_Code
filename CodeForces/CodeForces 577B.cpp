#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1000005
#define MAXM 1005

int a[MAXN];    //��¼ԭʼ����
int dp[MAXM][MAXM]; //ǰi�������ܵõ�������Ϊj

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        a[i]%=m;
    }
    if(n>m) //ò������ν�ĸ볲ԭ��
    {
        puts("YES");
        return 0;
    }
    dp[0][0]=1;
    //for(int i=0; i<=n; i++)
    //    dp[i][0]=1;
    for(int i=1; i<=n; i++) //dp
    {
        for(int j=0; j<=m; j++)
            dp[i][j]=(dp[i-1][j] || dp[i-1][(j+a[i])%m]);
    }
    if(dp[n][m])
        puts("YES");
    else
        puts("NO");
    return 0;
}
