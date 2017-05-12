#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 35
#define MAXM 1<<30

struct Points
{
    int x;
    int y;
} ans[MAXN];

vector <int> edge[MAXN]; //STL邻接表

int degree[MAXN];   //每个结点的度
int dx[]={0,-1,0,1}; //左上右下
int dy[]={-1,0,1,0}; //左上右下
int n;

void dfs(int u,int from,int x,int y,int len,int dir)    //dir为来的方向
{
    int ndir=0; //新的方向
    ans[u].x=x;
    ans[u].y=y;
    for(int i=0; i<edge[u].size(); i++)
    {
        int v=edge[u][i];
        if(v==from) //不返回父节点
            continue;
        if((ndir+2)%4==dir) //下一步走的方向不能与来时的方向相反
            ndir++;
        int nx=x+dx[ndir]*len;
        int ny=y+dy[ndir]*len;
        dfs(v,u,nx,ny,len/2,ndir);  //下一步的步长除2（步长按照2^30,2^29,...,2^1,2^0即2^k），因为2^0+2^1+...+2^(k-1)<2^k
        ndir++;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    //puts("ok");
    bool flag=true;
    for(int i=1; i<=n; i++)
    {
        if(degree[i]>4) //度数超过4肯定画不出来
            flag=false;
    }
    if(!flag)
        puts("NO");
    else
    {
        dfs(1,-1,0,0,1<<30,-1);
        puts("YES");
        for(int i=1; i<=n; i++)
            printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
