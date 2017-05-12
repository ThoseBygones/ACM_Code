#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 105
#define MAXE 1005


//���ڳ���ͼ��DFS������·��
class Hungary_DFS
{
private:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge(int to,int next):to(to),next(next) {}
        Edge() {}
    } e[MAXE];

    int mx[MAXN],my[MAXN];
    int vis[MAXN];
    int nk;
    int nx,ny;
    int cnt;

    void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }


    bool dfs(int u)
    {
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!vis[v])
            {
                vis[v] = true;
                if(my[v] == -1 || dfs(my[v]))
                {
                    my[v] = u;
                    mx[u] = v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init(int n,int m,int k)
    {
        cnt = 0;
        nx = n;
        ny = m;
        nk = k;
    }

    int hungary()
    {
        int res = 0;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        for(int i = 1; i <= nx; i++)
        {
            if(mx[i] == -1)
            {
                memset(vis, 0, sizeof(vis));
                if(dfs(i))
                    res++;
            }
        }
        return res;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        for(int i=0; i<nk; i++)
        {
            int task,u,v;
            scanf("%d%d%d",&task,&u,&v);
            if(u==0 || v==0)
                continue;
            addEdge(u,v);
        }
    }
} hungaryDFS;

int main()
{
    int n,m,k;
    while(~scanf("%d",&n),n)
    {
        scanf("%d%d",&m,&k);
        hungaryDFS.init(n,m,k);
        hungaryDFS.buildGraph();
        int ans=hungaryDFS.hungary();
        printf("%d\n",ans);
    }
    return 0;
}



#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 105
#define MAXE 1005


//����ϡ��ͼ�����٣�BFS�����
class Hungary_BFS
{
private:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge(int to,int next):to(to),next(next) {}
        Edge() {}
    } e[MAXE];

    int mx[MAXN],my[MAXN];
    int vis[MAXN];
    int pre[MAXN];
    int nk;
    int nx,ny;
    int cnt;

    void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }


    bool bfs(int st)
    {
        queue <int> q;
        q.push(st);
        pre[st] = -1;
        bool flag = false;
        while(!q.empty() && !flag)
        {
            int u = q.front();
            q.pop();
            for(int i = head[u]; ~i && !flag; i = e[i].next)
            {
                int v = e[i].to;
                if(vis[v] != st)
                {
                    vis[v] = st;
                    q.push(my[v]);
                    if(~my[v])  //my[v]!=-1
                        pre[my[v]] = u;
                    else
                    {
                        int a = u, b = v;
                        flag = true;
                        while(~a)   //a!=-1
                        {
                            int t = mx[a];
                            mx[a] = b;
                            my[b] = a;
                            a = pre[a];
                            b = t;
                        }
                    }
                }
            }
        }
        return mx[st] != -1;
    }

public:
    void init(int n,int m,int k)
    {
        cnt = 0;
        nx = n;
        ny = m;
        nk = k;
    }

    int hungary()
    {
        int res = 0;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        memset(vis, -1, sizeof(vis));
        for(int i = 1; i <= nx; i++)  //number from 1
        {
            if(mx[i] == -1)
            {
                if(bfs(i))
                    res++;
            }
        }
        return res;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        for(int i=0; i<nk; i++)
        {
            int task,u,v;
            scanf("%d%d%d",&task,&u,&v);
            if(u==0 || v==0)
                continue;
            addEdge(u,v);
        }
    }
} hungaryBFS;

int main()
{
    int n,m,k;
    while(~scanf("%d",&n),n)
    {
        scanf("%d%d",&m,&k);
        hungaryBFS.init(n,m,k);
        hungaryBFS.buildGraph();
        int ans=hungaryBFS.hungary();
        printf("%d\n",ans);
    }
    return 0;
}



/*�������ͼ�ĵ�ֳ������㼯x,y��
���ȴ�����x��δƥ��ĵ����bfs��ά��x��y������dx,dy��
���y����δƥ��ĵ���ô���ҵ�һ���������·����¼��ǰ���ȣ����ڸó��ȵĽ���bfs��
bfs��֮��õ��������·�������������㷨������������dy[v]==dx[u]+1���������㡣
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 105
#define MAXE 1005
#define INF 0x3f3f3f3f


class HopcroftKarp
{
private:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge(int to,int next):to(to),next(next) {}
        Edge() {}
    } edge[MAXE];

    int nx,ny;  //����Ҫƥ��ĵ㣬��Ϊx���ϵĵ��y���ϵĵ㡣nx,nyΪ�������е������
    int node;   //�ܽ������
    int nk;
    int cnt;
    int mx[MAXN],my[MAXN];  //mx��ʾ��x��Ե�y���,my��ʾ��y��Ե�x��š���Mx[i]��ֵ��ʾx������i�ŵ��ƥ��㣬My[j]��ֵ����y����j��ƥ��ĵ�
    int dx[MAXN],dy[MAXN];    //�������bfs������·�õ����飬����u->v�ɴ����dy[v]=dx[u]+1��dy,dx��ʾ�ڸ��Լ�����ı��
    int vis[MAXN];  //Ѱ������·�ı������
    int dis;


    void addEdge(int u,int v)
    {
        edge[cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt++;
    }

    bool bfs()   //Ѱ������·������ÿ��ֻѰ�ҵ�ǰ��̵�����·
    {
        queue <int> q;
        dis = INF;
        memset(dx,-1,sizeof(dx));
        memset(dy,-1,sizeof(dy));
        for(int i=1; i<=nx; i++)
        {
            if(mx[i]==-1)   //��δ�����Ľڵ���ӣ�����ʼ���νڵ����Ϊ0
            {
                q.push(i);
                dx[i]=0;
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(dx[u]>dis)
                break;
            for(int i=head[u]; i!=-1; i=edge[i].next)
            {
                int v = edge[i].to;
                if(dy[v] == -1)
                {
                    dy[v] = dx[u] + 1;
                    if(my[v] == -1) //�ҵ���һ������·��disΪ����·�յ�ı��
                        dis = dy[v];
                    else
                    {
                        dx[my[v]] = dy[v]+1;
                        q.push(my[v]);
                    }
                }
            }
        }
        return dis!=INF;
    }

    bool dfs(int u)
    {
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].to;
            if(!vis[v] && dy[v]==dx[u]+1)   //����õ�û�б����������Ҿ���Ϊ��һ�ڵ�+1
            {
                vis[v]=1;
                if(my[v]!=-1 && dy[v]==dis) //u�ѱ�ƥ�����ѵ����д��ڵ�����·�յ�ı�ţ��ٵݹ�Ѱ��Ҳ��������·��ֱ������
                    continue;
                if(my[v]==-1 || dfs(my[v])) //�����ر�Ҫע�⣬Mx[u] == -1 && dfs(u)�Ⱥ�˳��ǧ���ܻ���dfs֮��Mx[u]�ͻ�仯
                {
                    my[v]=u;
                    mx[u]=v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init(int n,int m,int k)
    {
        cnt = 0;
        memset(mx,-1,sizeof(mx));
        memset(my,-1,sizeof(my));
        nx = n;
        ny = m;
        nk = k;
    }

    int maxMatch()  //���ƥ��
    {
        int ans = 0;
        while(bfs())
        {
            memset(vis,0,sizeof(vis));
            for(int i=1; i<=nx; i++)
            {
                if(mx[i]==-1 && dfs(i))
                    ans++;
            }
        }
        return ans;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        for(int i=0; i<nk; i++)
        {
            int task,u,v;
            scanf("%d%d%d",&task,&u,&v);
            if(u==0 || v==0)
                continue;
            addEdge(u,v);
        }
    }
} hk;

int main()
{
    int n,m,k;
    while(~scanf("%d",&n),n)
    {
        scanf("%d%d",&m,&k);
        hk.init(n,m,k);
        hk.buildGraph();
        int ans=hk.maxMatch();
        printf("%d\n",ans);
    }
    return 0;
}
