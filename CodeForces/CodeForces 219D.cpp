#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f

struct Node
{
    int to;
    int cost;
    int next;
} e[MAXN<<1];

int head[MAXN];
int dp[MAXN][2];   //dp[i][0]表示以i为根从i出发遍历子树中需要反转的边数，dp[i][1]表示从i往其父节点方向走需要反转的边数
int cnt;
int n;

void addEdge(int u,int v,int w)
{
    e[cnt].to=v;
    e[cnt].cost=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs1(int u,int fa) //从i出发遍历子树
{
    //dp[u][0]=0;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            dfs1(v,u);
            dp[u][0]+=dp[v][0]+e[i].cost;
        }
    }
}

void dfs2(int u,int fa)
{
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            //从v点向其父结点遍历=从u点向v以外的子树遍历+从u点向其父节点遍历-从u向v走反转边的花费+从v向u走反转边的花费
            dp[v][1]=dp[u][0]-dp[v][0]+dp[u][1]-e[i].cost+e[i^1].cost;
            dfs2(v,u);
        }
    }
}

int main()
{
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    cnt=0;
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v,0);
        addEdge(v,u,1); //反向边费用设为1，即反转需要花费1
    }
    dfs1(1,-1);
    dfs2(1,-1);
    int ans=INF;
    for(int i=1; i<=n; i++)
    {
        ans=min(ans,dp[i][0]+dp[i][1]);
        //cout << dp[i][0]+dp[i][1] << endl;
    }
    printf("%d\n",ans);
    bool flag=true;
    for(int i=1; i<=n; i++)
    {
        if(ans==dp[i][0]+dp[i][1])
        {
            if(flag)
            {
                printf("%d",i);
                flag=false;
            }
            else
                printf(" %d",i);
        }
    }
    puts("");
    return 0;
}
