#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define MAXN 200005

int fa[MAXN];
int c[MAXN];    //袜子的颜色
int id[MAXN];   //集合的编号
int n,m,k;

vector <int> num[MAXN]; //记录所有点对应的根节点颜色的编号
map <int,int> cnt;  //记录每个根节点编号映射每个根节点出现的次数

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
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        fa[i]=i;
    for(int i=1; i<=n; i++)
        scanf("%d",&c[i]);
    for(int i=1; i<=m; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        unionset(l,r);  //把要在同一天穿的袜子连边
    }
    for(int i=1; i<=n; i++)
        num[findset(i)].push_back(c[i]);
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        cnt.clear();
        int Max=0;
        int sz=num[i].size();
        //if(sz<=1) //并查集里的点数量小于1，跳过计算（这一步可写可不写）
        //    continue;
        for(int j=0; j<sz; j++)
        {
            cnt[num[i][j]]++;   //记录各种颜色袜子的个数
            Max=max(Max,cnt[num[i][j]]);    //寻找同一颜色最多的袜子
        }
        ans+=sz-Max;    //每次将剩余的袜子染色成最多的那个颜色即可
    }
    printf("%d\n",ans);
    return 0;
}
