//Prim�㷨
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int cost[MAXN][MAXN];    //�洢����֮�������ڽӾ���
int vis[MAXN];  //��¼ĳ�������Ƿ��Լ�������MST
int dis[MAXN];  //��¼����֮�����̾���
int pre[MAXN];  //��¼ĳ�����ǰ���������ĸ��ڵ㣩
int used[MAXN][MAXN];   //��¼�ڽӾ����е�ĳ�����Ƿ��Ѿ����ù�
int Max[MAXN][MAXN]; //��¼����С��������ĳ����֮������·���е�����Ȩֵ
int n,m,ans;

int prim()
{
    int sum=0;
    memset(vis,0,sizeof(vis));
    memset(used,0,sizeof(used));
    memset(Max,0,sizeof(Max));
    for(int i=1; i<=n; i++)
    {
        dis[i]=cost[1][i];
        pre[i]=1;
    }
    pre[1]=-1;
    vis[1]=1;
    dis[1]=0;
    for(int i=1; i<n; i++)
    {
        int Min=INF;
        int temp=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dis[j]<Min)
            {
                temp=j;
                Min=dis[j];
            }
        }
        if(Min==INF)
            return -1;
        sum+=Min;
        vis[temp]=1;
        used[pre[temp]][temp]=used[temp][pre[temp]]=1;
        for(int j=1; j<=n; j++)
        {
            if(vis[j])  //�������������С��������
                Max[temp][j]=Max[j][temp]=max(Max[pre[temp]][j],dis[temp]);  //��¼������֮������Ȩֵ
            if(!vis[j] && cost[temp][j]<dis[j])
            {
                dis[j]=cost[temp][j];
                pre[j]=temp;
            }
        }
    }
    return sum;
}

int SMST()  //���С������
{
    int Min=INF;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(cost[i][j]!=INF && !used[i][j])  //���ñ�û�ù�
                Min=min(Min,ans+cost[i][j]-Max[i][j]);
        }
    }
    if(Min==INF)
        return -1;
    return Min;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int u,v,w;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    cost[i][j]=0;
                else
                    cost[i][j]=INF;
            }
        }
        while(m--)
        {
            cin >> u >> v >> w;
            cost[u][v]=cost[v][u]=w;
        }
        ans=prim();
        if(ans==-1)
            cout << "Not Unique!" << endl;
        else if(ans==SMST())
            cout << "Not Unique!" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}


//Kruskal�㷨
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
int mat[MAXN][MAXN];
int father[MAXN];

struct Points
{
    int u;
    int v;
    int len;
} p[MAXN*MAXN];

int dis[MAXN];

bool cmp(Points a,Points b)
{
    return a.len<b.len;
}

int findset(int r)
{
    while(father[r]>=0)
    {
        r=father[r];
    }
    return r;
}

void unionset(int fa,int fb)
{
    if(father[fa]<father[fb])
    {

        father[fa]=father[fa]+father[fb];
        father[fb]=fa;
    }
    else
    {
        father[fb]=father[fa]+father[fb];
        father[fa]=fb;
    }
}

void kruskal()
{
    memset(father,-1,sizeof(father));
    memset(dis,0,sizeof(dis));
    sort(p+1,p+1+m,cmp);
    int ans=0;
    int k=0;
    for(int i=1; i<=m && k<n-1; i++)
    {
        int uu=findset(p[i].u);
        int vv=findset(p[i].v);
        if(uu!=vv)
        {
            unionset(uu,vv);
            k++;
            ans+=p[i].len;
            dis[k]=i;
        }
    }

    for(int i=1; i<=n-1; i++)
    {
        int ans2=0,k2=0;
        memset(father,-1,sizeof(father));
        for(int j=1; j<=m; j++)
        {
            if(j==dis[i])
                continue;
            int uu=findset(p[j].u);
            int vv=findset(p[j].v);
            if(uu!=vv)
            {
                unionset(uu,vv);
                k2++;
                ans2+=p[j].len;
            }

        }
        if(k2!=n-1)
        {
            continue;
        }
        if(ans2==ans)
        {
            printf("Not Unique!\n");
            return ;
        }

    }
    printf("%d\n",ans);
}

int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%d%d",&n,&m);
        memset(p,0,sizeof(p));
        for(int i=1; i<=m; i++)
            scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].len);
        kruskal();
    }
    return 0;
}
