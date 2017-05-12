#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAXN 55
#define INF 0x3f3f3f3f
using namespace std;

struct Points
{
    int x;
    int y;
};

char maze[MAXN][MAXN];  //��¼����ĵ�ͼ
int vis[MAXN][MAXN];    //��¼��ͼ�ϵĵ�ķ������
int dis[MAXN*MAXN][MAXN*MAXN];    //��¼����֮�������ڽӾ���
int d[MAXN*MAXN];    //��¼������֮�����С����
int used[MAXN*MAXN];    //���ĳ����ŵĶ����Ƿ��Ѿ�������С������
int num[MAXN][MAXN];    //��¼����ı��
int len[MAXN][MAXN];    //��¼ĳ�㵽�����(x,y)�����̾���

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int n,m,cnt;

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void bfs(int x,int y)
{
    queue <Points> q;
    memset(vis,0,sizeof(vis));
    Points now,next;
    now.x=x;
    now.y=y;
    q.push(now);
    vis[now.x][now.y]=1;
    len[now.x][now.y]=0;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(num[now.x][now.y]!=-1)
            dis[num[x][y]][num[now.x][now.y]]=len[now.x][now.y];
        for(int i=0; i<4; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            if(inMap(next.x,next.y) && !vis[next.x][next.y] && maze[next.x][next.y]!='#')
            {
                vis[next.x][next.y]=1;
                len[next.x][next.y]=len[now.x][now.y]+1;
                q.push(next);
            }
        }
    }
}

int prim()
{
    memset(used,0,sizeof(used));
    int ans=0;
    for(int i=0; i<cnt; i++)
        d[i]=dis[0][i];
    used[0]=1;
    d[0]=0;
    int temp;
    for(int i=0; i<cnt-1; i++)
    {
        int Min=INF;
        for(int j=0; j<cnt; j++)
        {
            if(!used[j] && d[j]<Min)
            {
                temp=j;
                Min=d[j];
            }
        }
        used[temp]=1;
        ans+=Min;
        for(int j=0; j<cnt; j++)
        {
            if(!used[j] && dis[temp][j]<d[j])
                d[j]=dis[temp][j];
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char temp[MAXN];
        cin >> m >> n;
        gets(temp); //�������ݱȽ����⣬��˵�ж���ո������Ҫ�ų����Ƕ����������Ӱ��
        for(int i=0; i<n; i++)
            gets(maze[i]);  //��ͼ���пո�
        /*for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout << maze[i][j];
            cout << endl;
        }*/
        cnt=1;  //S��ֱ�ӱ��Ϊ0
        memset(num,0,sizeof(num));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(maze[i][j]=='A') //A���1��ʼ���
                    num[i][j]=cnt++;
                if(maze[i][j]=='S') //S��ֱ�ӱ��Ϊ0
                    num[i][j]=0;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(maze[i][j]=='S' || maze[i][j]=='A')
                    bfs(i,j);
            }
        }
        int ans=prim();
        cout << ans << endl;
    }
    return 0;
}
