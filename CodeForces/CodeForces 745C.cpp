#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define MAXM 100005

int fa[MAXN];
int num[MAXN];  //该连通分量中包含的结点的数量
int gov[MAXN];  //是否为政府结点
int n,m,k;

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

int unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        num[yy]+=num[xx];   //合并结点时统计结点数量
        if(gov[xx])
            gov[yy]=1;
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
    {
        fa[i]=i;
        num[i]=1;
        gov[i]=0;
    }
    while(k--)
    {
        int c;
        scanf("%d",&c);
        gov[c]=1;   //标记政府结点
    }
    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        unionset(u,v);
    }
    int cnt=0;  //不含政府结点的连通分量数量
    int res=0;  //包含政府结点的连通分量内结点数
    int ans=0;  //总的需要新增的边数
    for(int i=1; i<=n; i++)
    {
        if(fa[i]==i)
        {
            if(!gov[i]) //不含政府结点的连通分量任意组合
                cnt+=num[i];
            else    //包含政府结点的连通分量选包含结点数量最多的
            {
                res=max(res,num[i]);
                ans+=num[i]*(num[i]-1)/2; //累加每个包含政府结点的连通分量内需要连上的总边数
            }
        }
    }
    cnt+=res;
    ans-=res*(res-1)/2; //减去重复计算了的被选中的包含政府结点的连通分量的总边数
    ans+=cnt*(cnt-1)/2-m;   //再加上不含政府结点的连通分量的总边数
    printf("%d\n",ans);
    return 0;
}
