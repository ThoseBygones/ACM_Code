#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1005

int g[MAXN][MAXN];  //邻接矩阵
int fa[MAXN];   //记录父亲
int in[MAXN];   //入度
int out[MAXN];  //出度
int belong[MAXN];   //记录每个点属于的集合编号：1--最轻；2--中等；3--最重
int n,m;

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void mergeset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
        fa[xx]=yy;
}

void init()
{
    memset(g,0,sizeof(g));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(belong,0,sizeof(belong));
    for(int i=1; i<=n; i++)
        fa[i]=i;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    init();
    for(int i=1; i<=m; i++)
    {
        int u,v;
        char c;
        scanf("%d%c%d",&u,&c,&v);
        if(c=='=')
            mergeset(u,v);
        if(c=='<')  //建立有向图，重量小点的指向重量大的点
        {
            g[u][v]=1;  //记录双向关系
            g[v][u]=-1;
            out[u]++;
            in[v]++;
        }
        if(c=='>')
        {
            g[v][u]=1;
            g[u][v]=-1;
            in[u]++;
            out[v]++;
        }
    }
    for(int i=1; i<=n; i++) //所以结点出入度统计到父节点
    {
        in[findset(i)]+=in[i];
        out[findset(i)]+=out[i];
    }
    for(int i=1; i<=n; i++) //对所有父节点进行统计
    {
        if(findset(i)==i && in[i] && out[i])
            belong[i]=2;
    }

    for(int i=1; i<=n; i++)
    {
        if(belong[findset(i)]==2)
        {
            for(int j=1; j<=n; j++)
            {
                if(g[i][j]==1)
                    belong[findset(j)]=3;
                if(g[i][j]==-1)
                    belong[findset(j)]=1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        int temp=belong[findset(i)];
        if(temp==0)
            printf("?");
        if(temp==1)
            printf("B");
        if(temp==2)
            printf("R");
        if(temp==3)
            printf("W");
    }
    puts("");
    return 0;
}
