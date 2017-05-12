#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

int w[MAXN],b[MAXN];
int fa[MAXN];
int n,m,wei;
int gw[MAXN],gb[MAXN];  //每个group的weight/beauty总和
int dp[MAXN];   //dp[i]相当于空间为i的背包能容纳的最大beauty

vector <int> v[MAXN];

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
        fa[xx]=yy;
}

int main()
{
    scanf("%d%d%d",&n,&m,&wei);
    memset(dp,0,sizeof(dp));
    memset(gw,0,sizeof(gw));
    memset(gb,0,sizeof(gb));
    for(int i=1; i<=n; i++) //UF-set初始化
        fa[i]=i;
    for(int i=1; i<=n; i++)
        scanf("%d",w+i);
    for(int i=1; i<=n; i++)
        scanf("%d",b+i);
    for(int i=1; i<=m; i++) //UF-set
    {
        int u,v;
        scanf("%d%d",&u,&v);
        unionset(u,v);
    }
    for(int i=1; i<=n; i++)
    {
        int temp=findset(i);    //find root
        v[temp].push_back(i);   //每个组有哪些人
        gw[temp]+=w[i]; //累加每组的weight
        gb[temp]+=b[i]; //累加每组的beauty
    }
    for(int i=1; i<=n; i++) //遍历所有组
    {
        if(v[i].size()==0)  //该root组里没人
            continue;
        for(int j=wei; j>0; j--)  //转化为背包问题，总重量为wei的01背包
        {
            if(j>=gw[i]) //背包空间还够，考虑如果整组装入的beauty会不会更大
                dp[j]=max(dp[j],dp[j-gw[i]]+gb[i]);
            for(int k=0; k<v[i].size(); k++)    //每组里要么选一个要么全选，先考虑只选一个的情况
            {
                if(j>=w[v[i][k]])    //背包里还有剩余空间
                    dp[j]=max(dp[j],dp[j-w[v[i][k]]]+b[v[i][k]]);
            }
        }
    }
    printf("%d\n",dp[wei]);
    return 0;
}
