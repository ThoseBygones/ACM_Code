#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 225
#define MAXM 25
#define MAXE 100005
#define INF 0x3f3f3f3f


class Dinic
{
private:
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    int rowsum[MAXN],colsum[MAXM];
    int b[MAXN][MAXM],c[MAXN][MAXM];    //�����½硢�����Ͻ�
    int ans[MAXN][MAXM];    //��¼ʵ���������
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s,t,cnt;    //����Դ�㳬�����
    int S,T;    //Դ����
    int n,m;
    //int node;
    bool flag;

    bool bfs()
    {
        memset(d,-1,sizeof(d));
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge &ed = e[i];
                if(d[ed.to]==-1&&ed.cap>ed.flow)
                {
                    d[ed.to] = d[x]+1;
                    q.push(ed.to);
                }
            }
        }
        return d[t]!=-1;
    }
    int dfs(int x,int a)
    {
        if(x==t||a==0) return a;
        int flow = 0,f;
        for(; ~cur[x]; cur[x] = nxt[cur[x]])
        {
            Edge &ed = e[cur[x]];
            if(d[ed.to]==d[x]+1&&(f = dfs(ed.to,min(ed.cap-ed.flow,a)))>0)
            {
                flow+=f;
                ed.flow+=f;
                e[cur[x]^1].flow-=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }

    void addEdge(int from,int to,int cap)
    {
        e[cnt] = Edge(from,to,cap,0);
        int tmp = head[from];
        head[from] = cnt;
        nxt[cnt++] = tmp;
        e[cnt] = Edge(to,from,0,0);
        tmp = head[to];
        head[to] = cnt;
        nxt[cnt++] = tmp;
    }
public:
    void init(int nn,int mm)
    {
        cnt = 0;
        flag=true;
        n=nn;
        m=mm;
        memset(head,-1,sizeof(head));
        memset(ans,0,sizeof(ans));
        memset(b,0,sizeof(b));
        memset(c,0x3f,sizeof(c));
        S=0;
        T=n+m+1;
        s=T+1;
        t=s+1;
        for(int i=1; i<=n; i++)
            scanf("%d",&rowsum[i]);
        for(int i=1; i<=m; i++)
            scanf("%d",&colsum[i]);
    }

    void buildMatrix()
    {
        int num;
        scanf("%d",&num);
        while(num--)
        {
            int u,v,lim;
            char ch;
            scanf("%d %d %c %d",&u,&v,&ch,&lim);
            int sx,ex,sy,ey;
            sx=ex=u;
            sy=ey=v;
            if(!u)
            {
                sx=1;
                ex=n;
            }
            if(!v)
            {
                sy=1;
                ey=m;
            }
            for(int i=sx; i<=ex; i++)
            {
                for(int j=sy; j<=ey; j++)
                {
                    if(ch=='=')
                        b[i][j]=c[i][j]=lim;
                    else if(ch=='<')
                        c[i][j]=min(c[i][j],lim-1);
                    else
                        b[i][j]=max(b[i][j],lim+1);
                    if(c[i][j]<b[i][j])
                        flag=false;
                }
            }
        }
        scanf("\n");
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=t; i++)
                cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    //���½������
    //s��tΪ����Դ��ͳ������
    //S��TΪԴ���
    //�Ȱ����¹�ͼ�ж��Ƿ��п���������T->S֮������һ����ȨֵΪINF�ıߣ�ת��Ϊ��Դ�����½����������
    //Ȼ��head[s] = -1,head[t] = -1;s = S,t = T;
    //��һ��S->T���������Ϊ��
    void buildGraph()
    {
        if(!flag)
        {
            puts("IMPOSSIBLE");
            return ;
        }
        int sum=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                addEdge(i,j+n,c[i][j]-b[i][j]); //������һ���߲�ߣ�(u,v,0,c-l)
                sum+=b[i][j];
                if(b[i][j])
                {
                    addEdge(s,j+n,b[i][j]); //��ӱ�(s,v,0,l)
                    addEdge(i,t,b[i][j]);   //��ӱ�(u,t,0,l)
                }
            }
        }
        addEdge(T,S,INF);   //Դ����֮����һ������Ϊ�����ı�
        int temp=0;
        for(int i=1; i<=n; i++)
        {
            sum+=rowsum[i];
            temp+=rowsum[i];
            addEdge(s,i,rowsum[i]);
            //addEdge(S,t,rowsum[i]);
        }
        addEdge(S,t,temp);
        temp=0;
        for(int j=1; j<=m; j++)
        {
            sum+=colsum[j];
            temp+=colsum[i];
            addEdge(j+n,t,colsum[j]);
            //addEdge(s,T,colsum[j]);
        }
        addEdge(s,T,temp);
        int res=maxFlow();
        //cout << res << "#" << sum << endl;
        if(res<sum)
            puts("IMPOSSIBLE");
        else
        {
            for(int i=1; i<=n; i++)
            {
                for(int j = head[i]; ~j; j = nxt[j])
                    ans[i][e[j].to-n]=e[j].flow;
            }
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<m; j++)
                    printf("%d ",ans[i][j]+b[i][j]);
                printf("%d\n",ans[i][m]+b[i][m]);
            }
        }
    }
} dinic;

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        dinic.init(n,m);
        dinic.buildMatrix();
        dinic.buildGraph();
        if(t)
            puts("");   //ZOJû������WA
    }
    return 0;
}
