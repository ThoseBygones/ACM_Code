#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MOD 10000

int grid[MAXN][MAXN];
int dp[MAXN][MAXN]; //�ߵ���(i,j)���ܷ�����
int n,m;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

int dfs(int x,int y)    //���仯����
{
    if(dp[x][y])    //��״̬֮ǰ�Ѿ�������������Ҫ�ٴ���
        return dp[x][y];
    for(int i=0; i<=grid[x][y]; i++)
    {
        for(int j=0; i+j<=grid[x][y]; j++)
        {
            if(inMap(x+i,y+j) && !(i==0 && j==0))
                dp[x][y]=(dp[x][y]+dfs(x+i,y+j))%MOD;   //�ݹ�Ĺ���
        }
    }
    return dp[x][y];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%d",&grid[i][j]);
        }
        memset(dp,0,sizeof(dp));
        dp[n][m]=1; //�е����Ƶ�������
        printf("%d\n",dfs(1,1));
    }
    return 0;
}
