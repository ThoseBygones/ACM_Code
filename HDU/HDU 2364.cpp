#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 85
using namespace std;

struct Point
{
    int x;
    int y;
    int step;
    int pre;
};

Point s;
char maze[MAXN][MAXN];
int vis[MAXN][MAXN][5]; //��¼���ʵ�����������ά�ģ���Ϊ��Ҫ��¼ĳ����Ӳ�ͬ����ķ������
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};    //�������£�ͬ������ͬΪż������������
int n,m;

queue <Point> q;

bool reachEdge(int x,int y) //�ж��Ƿ񵽴��Թ��߽磨Ҳ�����Ƿ��Ѿ��߳��Թ��ˣ�
{
    if(x==0 || x==n-1 || y==0 || y==m-1)
        return true;
    return false;
}

int bfs()
{
    while(!q.empty())
        q.pop();
    q.push(s);
    Point now,next;
    bool flag;  //�ܷ������䵽���յ�ı�־
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        flag=true;
        for(int i=0; i<4; i++)
        {
            if(i%2==now.pre%2)  //�����һ������һ������ͬ���������
                continue;
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            next.step=now.step+1;
            next.pre=i;
            if(maze[next.x][next.y]=='#')
                continue;
            flag=false; //��ת����ת�����Ĳ���ǽ�ڣ�����
            if(vis[next.x][next.y][i])  //�������ʹ�����˵����ǰ�ߵ�·���޷��߳��Թ�
                continue;
            vis[next.x][next.y][i]=1;
            if(reachEdge(next.x,next.y))
                return next.step;
            q.push(next);
        }
        if(flag)    //��ת����ת�������У�ֻ��ֱ�ߣ�
        {
            int temp=now.pre;
            next.x=now.x+dx[temp];
            next.y=now.y+dy[temp];
            next.step=now.step+1;
            next.pre=temp;
            if(maze[next.x][next.y]=='#')
                continue;
            if(vis[next.x][next.y][temp])
                continue;
            vis[next.x][next.y][temp]=1;
            if(reachEdge(next.x,next.y))
                return next.step;
            q.push(next);
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0; i<n; i++)
            cin >> maze[i];
        bool flag=false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(maze[i][j]=='@')
                {
                    s.x=i;
                    s.y=j;
                    s.step=0;
                    s.pre=-1;
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        memset(vis,0,sizeof(vis));
        for(int i=0; i<4; i++)
            vis[s.x][s.y][i]=1; //��㲻���ٱ��ظ��ߣ�����϶�������̵�
        if(reachEdge(s.x,s.y))  //����㼴���յ㣬��ֱ�����0
        {
            cout << "0" << endl;
            continue;
        }
        int ans=bfs();
        cout << ans << endl;
    }
    return 0;
}
