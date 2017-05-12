#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 305
#define INF 1000000000000000LL

LL cost[MAXN][MAXN];    //��¼ÿ����˾�Ļ���
LL dp[MAXN][MAXN];  //ǰi���㸲��j����Ҫ�Ļ���
int n,m,k;

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=0; i<=n+1; i++)
        {
            for(int j=0; j<=n+1; j++)
            {
                dp[i][j]=INF;
                cost[i][j]=INF;
            }
        }
        for(int i=1; i<=m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            cost[a][b]=min(cost[a][b],(LL)c);
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=n; j>=i; j--)
                cost[i][j]=min(cost[i][j],cost[i][j+1]);    //�Ƿ���ڷ���ʹ���i���ӵ���j+1���ӱ�ԭ�������i����j���Ӹ�����
        }
        dp[0][0]=0;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(dp[i][j]!=INF)
                {
                    dp[i+1][j]=min(dp[i][j],dp[i+1][j]);    //�Ƿ���ڷ���ʹ�ǰi�����е�j���ӱ��ǰi+1�����е�j���Ӹ�����
                    for(int l=1; l<=k-j; l++)   //����Ҫ��Ŀ�ʣk-j��
                    {
                        if(i+l<=n)
                            dp[i+l][j+l]=min(dp[i+l][j+l],dp[i][j]+cost[i+1][i+l]); //�Ƿ���ڷ���ʹ�ٶ�ʹ��һ����˾��i+1��i+l��cost[i+1][i+l]���ӻ��ԭ���ķ���������
                    }
                }
            }
        }
        if(dp[n][k]==INF)
            cout << "-1" << endl;
        else
            cout << dp[n][k] << endl;
    }
}
