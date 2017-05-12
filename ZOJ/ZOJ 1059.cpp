#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 25
#define MAXE 505


//适于稠密图，DFS找增广路快
class Hungary_DFS
{
private:
    struct Node
    {
        int id;
        char s[25];
        bool operator <(const Node& a) const
        {
            if(strcmp(this->s,a.s)<=0)
                return true;
            return false;
        }
    } name[MAXN],userid[MAXN];
    int g[MAXN][MAXN];
    int mx[MAXN],my[MAXN];
    int vis[MAXN];
    int in[MAXN];   //判断每个嫌疑犯是否在hideout内
    int match[MAXN];    //记录匹配情况
    int n;
    int nx,ny;
    int cnt;
    int order[MAXN];

    bool dfs(int u)
    {
        for(int v = 0; v < n; v++)
        {
            if(!vis[v] && g[u][v])
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
    void init(int a)
    {
        cnt = 0;
        n = a;
    }

    int hungary()
    {
        int res = 0;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        for(int i = 0; i < n; i++)
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
        for(int i=0; i<n; i++)
        {
            scanf("%s",userid[i].s);
            userid[i].id=i;
        }
        memset(g,-1,sizeof(g));
        memset(in,0,sizeof(in));
        char a[5];
        char op;
        char temp[25];
        while(~scanf("%s",temp))
        {
            op=temp[0];
            if(op=='Q')
                break;
            scanf("%s",temp);
            if(op=='E')
            {
                int i;
                for(i=0; i<cnt && strcmp(temp,name[i].s)!=0; i++);
                if(i==cnt)
                {
                    strcpy(name[cnt].s,temp);
                    name[cnt].id=cnt;
                    cnt++;
                }
                in[i]=1;    //标记进入hideout
            }
            else if(op=='L')
            {
                int i;
                for(i=0; i<cnt && strcmp(temp,name[i].s)!=0; i++);
                in[i]=0;    //标记离开hideout
            }
            else if(op=='M')
            {
                int i;
                for(i=0; i<n && strcmp(temp,userid[i].s)!=0; i++);
                for(int j=0; j<cnt; j++)
                {
                    if(!in[j])
                        g[j][i]=0; //当前不在hideout内的人不可能有此id
                }
                for(int j=cnt; j<n; j++)
                    g[j][i]=0; //没有进入过hideout的人同样不可能有此id
            }
        }
    }
    void checkMatch()
    {
        memset(match,-1,sizeof(match));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(g[i][j])    //临时删除某个匹配的连边
                {
                    g[i][j]=0;
                    if(hungary()!=n)    //判断该边是否为必须边，如果不可删除，则保留
                    {
                        g[i][j]=1;
                        match[i]=j;
                        break;
                    }
                    g[i][j]=1;
                }
            }
        }
        /*for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                printf("%d ",g[i][j]);
            puts("");
        }*/
        /*for(int i=0; i<n; i++)
            order[i]=i;
        sort(order,order+n,cmp);
        */
        sort(name,name+n);
    }

    void print()
    {
        for(int i=0; i<n; i++)
        {
            printf("%s:",name[i].s);
            if(match[name[i].id]==-1)
                puts("???");
            else
                printf("%s\n",userid[match[name[i].id]].s);
        }
    }
} hungaryDFS;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        hungaryDFS.init(n);
        hungaryDFS.buildGraph();
        hungaryDFS.checkMatch();
        hungaryDFS.print();
        if(t)
            puts("");
    }
    return 0;
}
