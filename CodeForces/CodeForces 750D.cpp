#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 1e9
#define MAXN 310

int grid[MAXN][MAXN];
int vis[MAXN][MAXN][30][10];    //vis[i][j][k][l]Ϊ��k����(i,j)�Ƿ񱻴ӷ���l���ʹ�
int a[35];
int dx[]= {1,1,0,-1,-1,-1,0,1}; //���¡����¡��������ϡ����ϡ����ϡ����ҡ�����
int dy[]= {0,-1,-1,-1,0,1,1,1}; //���¡����¡��������ϡ����ϡ����ϡ����ҡ�����
int n;

struct Node
{
    int x;
    int y;
    int step;   //�̻��Ĳ���
    int dir;    //�̻��ķ���
};

void bfs()
{
    queue <Node> q;
    Node temp,now,next;
    temp.x=150;
    temp.y=150;
    temp.step=1;
    temp.dir=0;
    q.push(temp);
    vis[150][150][1][0]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        int nx=now.x;
        int ny=now.y;
        for(int i=1; i<=a[now.step]; i++)
        {
            nx+=dx[now.dir];
            ny+=dy[now.dir];
            grid[nx][ny]=1;
        }
        if(now.step!=n)
        {
            int l=(now.dir-1+8)%8;  //��ʱ��ƫת45��
            int r=(now.dir+1)%8;    //˳ʱ��ƫת45��
            next.x=nx;
            next.y=ny;
            next.step=now.step+1;
            if(!vis[next.x][next.y][next.step][l])  //ĳ��������ʱ��ƫ45��δ������
            {
                vis[next.x][next.y][next.step][l]=1;
                next.dir=l;
                q.push(next);
            }
            if(!vis[next.x][next.y][next.step][r])  //ĳ������˳ʱ��ƫ45��δ������
            {
                vis[next.x][next.y][next.step][r]=1;
                next.dir=r;
                q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",a+i);
    memset(grid,0,sizeof(grid));
    memset(vis,0,sizeof(vis));
    bfs();
    int ans=0;
    for(int i=0; i<=305; i++)
    {
        for(int j=0; j<=305; j++)
        {
            if(grid[i][j])
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
