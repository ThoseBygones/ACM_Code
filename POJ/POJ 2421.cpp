#include<iostream>
#include<algorithm>
using namespace std;

int vmap[105][105],par[105];

struct village
{
    int s;
    int e;
    int len;
} v[10005];

int cmp(village a,village b)
{
    return a.len < b.len;
}

int findset(int r)
{
    if(par[r]!=r)
        return par[r]=findset(par[r]);
    return r;
}

bool mergeset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
    {
        par[yy]=xx;
        return true;
    }
    return false;
}

int kruskal(int num)
{
    int sum=0;
    for(int i=0; i<num; i++)
    {
        if(mergeset(v[i].s,v[i].e))
            sum+=v[i].len;
    }
    return sum;
}

int main()
{
    int n,q,a,b;
    while(cin >> n)
    {
        for(int i=1; i<=n; i++)
            par[i]=i;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cin >> vmap[i][j];
        int cnt=0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                v[cnt].s=i;
                v[cnt].e=j;
                v[cnt].len=vmap[i][j];
                cnt++;
            }
        }
        cin >> q;
        while(q--)
        {
            cin >> a >> b;
            mergeset(a,b);
        }
        sort(v,v+cnt,cmp);
        int sum=kruskal(cnt);
        cout << sum << endl;
    }
    return 0;
}

//PrimËã·¨
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
int mp[110][110];
int dis[110];
int vis[110];

int prim()
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(int i=1; i<=n; i++)
        dis[i]=mp[1][i];
    for(int i=2; i<=n; i++)
    {
        int Min=INF;
        int temp=0;
        for(int j=2; j<=n; j++)
        {
            if(!vis[j] && dis[j]<Min)
            {
                temp=j;
                Min=dis[j];
                //printf("%d\n",Min);
            }
        }
        ans+=Min;
        vis[temp]=1;
        for(int j=2; j<=n; j++)
        {
            if(!vis[j] && mp[temp][j]<dis[j])
                dis[j]=mp[temp][j];
        }
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            scanf("%d",&mp[i][j]);
    }
    scanf("%d",&m);
    int u,v;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&u,&v);
        mp[u][v]=mp[v][u]=0;
    }
    int ans=prim();
    printf("%d\n",ans);
    return 0;
}
