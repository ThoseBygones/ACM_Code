#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 105
using namespace std;

char mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]= {-1,-1,0,1,1,1,0,-1}; ///�˸�����
int dy[]= {0,-1,-1,-1,0,1,1,1};
int m,n;

bool inMap(int x,int y) ///�ж���һ���Ƿ��ڵ�ͼ��Χ��
{
    if(x>=0 && x<m && y>=0 && y<n)
        return true;
    return false;
}

void dfs(int x,int y)
{
    vis[x][y]=1;    ///���ʼ�¼
    for(int i=0; i<8; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny) && !vis[nx][ny] && mp[nx][ny]=='@') ///�ж���һ���ǲ��ǿ���
        {
            vis[nx][ny]=1;
            dfs(nx,ny); ///����������һ������
        }
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        if(m==0 && n==0)
            break;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<m; i++)
            scanf("%s",mp[i]);
        int cnt=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mp[i][j]=='@' && !vis[i][j])
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}


///BFSʵ��
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 105
using namespace std;

int dx[]= {-1,-1,0,1,1,1,0,-1};
int dy[]= {0,-1,-1,-1,0,1,1,1};
char mp[MAXN][MAXN];
int m,n;
int vis[MAXN][MAXN];

struct Point
{
    int x;
    int y;
};

queue <Point> q;

bool inMap(int x,int y) ///�ж���һ���Ƿ��ڵ�ͼ��Χ��
{
    if(x>=0 && x<m && y>=0 && y<n)
        return true;
    return false;
}

void bfs(int x, int y)
{
    while(!q.empty())
        q.pop();
    Point cur,next;
    cur.x = x;
    cur.y = y;
    //vis[cur.x][cur.y]=1;
    q.push(cur);

    while(!q.empty())
    {
        Point temp = q.front();
        q.pop();
        vis[temp.x][temp.y] = 1;
        for(int i=0; i<8; i++)
        {
            next.x=temp.x+dx[i];
            next.y=temp.y+dy[i];
            if(inMap(next.x,next.y) && !vis[next.x][next.y] && mp[next.x][next.y]=='@')
            {
                vis[next.x][next.y]=1;
                q.push(next);
                //cur.x=next.x;
                //cur.y=next.y;
            }
        }
    }
}

int main(void)
{
    int ans;
    while(scanf("%d%d",&m,&n)!=EOF && m)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0; i<m; i++)
            scanf("%s",&mp[i]);
        ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mp[i][j]=='@' && !vis[i][j])
                {
                    ans++;
                    bfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
