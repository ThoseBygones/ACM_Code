#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int edge[MAXN][MAXN];
int vis[MAXN];
int n,a,b,c;
int sum;

void dfs(int u,int fa)
{
    vis[u]=1;
    for(int i=1; i<=n; i++)
    {
        //cout << "$" << edge[u][i] << endl;
        if(edge[u][i]!=-1 && !vis[i] && i!=fa)
        {
            //cout << "->" << i << endl;
            sum+=edge[u][i];
            //cout << "#" << sum << endl;
            dfs(i,u);
        }
    }
}

int main()
{
    scanf("%d",&n);
    memset(edge,-1,sizeof(edge));
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        edge[a][b]=0;
        edge[b][a]=c;
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout << edge[i][j];
        cout << endl;
    }*/
    int ans=INF;
    for(int i=1; i<=n; i++)
    {
        memset(vis,0,sizeof(vis));
        sum=0;
        if(edge[1][i]!=-1)
        {
            //cout << "->" << i << endl;
            sum+=edge[1][i];
            //cout << "#" << sum << endl;
            dfs(i,1);
            ans=min(ans,sum);
        }
    }
    printf("%d\n",ans);
    return 0;
}
