///POJ 3159
///����Ϊ������������·�еĲ��Լ��ϵͳ���⣨����һ��������Լ�������������·��������

///��һ�γ��ԣ�ʹ�ö����Ż���spfa����queue+spfa(spfa+bfs)
///�ύ��OJ�����Խ����TLE
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define N 30005
#define M 150005
using namespace std;

int n,m;
int head[N],dis[N],vis[N];

struct candies
{
    int u;
    int v;
    int w;
    int next;
} c[M];

void spfa()
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        dis[i]=INF;
    dis[1]=0;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x]; i!=-1; i=c[i].next)
        {
            int y=c[i].v;
            int z=c[i].w;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
    //while(~scanf("%d%d",&n,&m))
    while(cin >> n >> m)
    {
        for(int i=1; i<=n; i++)
            head[i]=-1;
        for(int i=1; i<=m; i++)
        {
            cin >> c[i].u >> c[i].v >> c[i].w;
            //scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);
            c[i].next=head[c[i].u];
            head[c[i].u]=i;
        }
        spfa();
        //printf("%d\n",dis[n]);
        cout << dis[n] << endl;
    }
    return 0;
}

///�������Բ�ʹ��memset������ʹ��scanf����cin�Ż��Լ��٣������ȻTLE������


///�ڶ��γ��ԣ�ʹ�ö�ջ�Ż���spfa����stack+spfa(spfa+dfs)
///�ύ��OJ�����Խ����AC
///G++�ύ�����Memory: 2952 KB  Time: 516 ms
///C++�ύ�����Memory: 2568 KB  Time: 735 ms
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define INF 0x3f3f3f3f
#define N 30005
#define M 150005
using namespace std;

int n,m;
int head[N],dis[N],vis[N];

struct candies
{
    int u;
    int v;
    int w;
    int next;
} c[M];

void spfa()
{
    stack<int> s;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        dis[i]=INF;
    dis[1]=0;
    s.push(1);
    vis[1]=1;
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        vis[x]=0;
        for(int i=head[x]; i!=-1; i=c[i].next)
        {
            int y=c[i].v;
            int z=c[i].w;
            if(dis[y]>dis[x]+z)
            {
                dis[y]=dis[x]+z;
                if(!vis[y])
                {
                    vis[y]=1;
                    s.push(y);
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    //while(cin >> n >> m)
    {
        for(int i=1; i<=n; i++)
            head[i]=-1;
        for(int i=1; i<=m; i++)
        {
            //cin >> c[i].u >> c[i].v >> c[i].w;
            scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);
            c[i].next=head[c[i].u];
            head[c[i].u]=i;
        }
        spfa();
        printf("%d\n",dis[n]);
        //cout << dis[n] << endl;
    }
    return 0;
}
///ע�⣺ʹ��cin��Ȼ���ΪTLE������ʹ��scanf�Ժ���ΪAC������
