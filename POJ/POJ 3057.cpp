#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 15 //13也行，但是MAXM和MAXE开小了会RE，具体原因我也很迷... = =
#define MAXM 4*MAXN*MAXN*MAXN    //MAXN*MAXN个人作为X点集，MAXN*MAXN*MAXN个时间t(t=0~MAXN*MAXN)门作为Y点集
#define MAXE 2*MAXN*MAXN*MAXN*MAXN*MAXN    //X集与Y集之间都连边（事实上边大约只有不到这个数的一半）
#define PII pair<int,int>
#define MP make_pair

static const int dx[4]= {-1,0,0,1};
static const int dy[4]= {0,-1,1,0};

//邻接表
class Hungary_DFS
{
private:
    int head[MAXM];
    struct Edge
    {
        int to,next;
        Edge(int to,int next):to(to),next(next) {}
        Edge() {}
    } e[MAXE];

    int mx[MAXM],my[MAXM];
    int vis[MAXM];
    int nx,ny;
    int cnt;
    int n;
    int xx,yy;

    bool inMap(int x,int y)
    {
        if(x>=0 && x<xx && y>=0 && y<yy)
            return true;
        return false;
    }

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
    char room[MAXN][MAXN];
    vector <PII> p,d;  //人的坐标和门的坐标
    int dis[MAXN][MAXN][MAXN][MAXN];  //各人与各门之间的最近距离

    void bfs(int x,int y,int d[MAXN][MAXN])   //计算人与门的最近距离
    {
        queue <PII> q;
        d[x][y]=0;
        q.push(MP(x,y));
        while(!q.empty())
        {
            PII cur=q.front();
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nx=cur.first+dx[i];
                int ny=cur.second+dy[i];
                if(inMap(nx,ny) && room[nx][ny]=='.' && d[nx][ny]<0)
                {
                    d[nx][ny]=d[cur.first][cur.second]+1;
                    q.push(MP(nx,ny));
                }
            }
        }
    }

    void init(int a,int b)
    {
        cnt = 0;
        xx = a;
        yy = b;
    }

    void hungary()
    {
        int res = 0;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        for(int i = 0; i < n*nx; i++)   //枚举门的集合
        {
            if(mx[i] == -1)
            {
                memset(vis, 0, sizeof(vis));
                if(dfs(i))
                {
                    res++;
                    if(res==ny) //所有人都能逃出
                    {
                        printf("%d\n",i/nx+1);
                        return ;
                    }
                }

            }
        }
        puts("impossible");
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        nx=d.size();
        ny=p.size();
        for(int i=0; i<nx; i++) //枚举每个门
        {
            for(int j=0; j<ny; j++) //枚举每个人
            {
                if(dis[d[i].first][d[i].second][p[j].first][p[j].second]>=0)    //若这个人能到达某个门
                {
                    for(int k=dis[d[i].first][d[i].second][p[j].first][p[j].second]; k<=n; k++)
                        addEdge((k-1)*nx+i,n*nx+j); //该人与不同时间的门建边
                }
            }
        }
    }

    void solve()
    {
        for(int i=0; i<xx; i++)
            scanf("%s",room[i]);

        n=xx*yy;    //时间上界，超过这个时间表示有的人无法逃脱
        p.clear();
        d.clear();
        memset(dis,-1,sizeof(dis));

        for(int i=0; i<xx; i++)
        {
            for(int j=0; j<yy; j++)
            {
                if(room[i][j]=='D') //计算每个人到某个门的最短距离
                {
                    d.push_back(MP(i,j));
                    bfs(i,j,dis[i][j]);
                }
                if(room[i][j]=='.')
                    p.push_back(MP(i,j));
            }
        }

        buildGraph();

        if(ny==0)
        {
            puts("0");
            return ;
        }

        hungary();
    }
} hungaryDFS;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        hungaryDFS.init(n,m);
        hungaryDFS.solve();
    }
    return 0;
}
