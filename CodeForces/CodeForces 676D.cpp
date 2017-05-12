#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

struct Node
{
    int x;
    int y;
    int step;
    int status;
};

int maze[MAXN][MAXN];
int vis[MAXN][MAXN][5];  //最后一维为转向次数（最多4次）
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};    //左下右上
int n,m;
int sx,sy,ex,ey;

int getStatus(char c)   //转化为数字，利用二进制形式表示各个方向是否有门（上右下左）
{
    if(c=='+')  //+ means this block has 4 doors (one door to each neighbouring block);
        return 15;  //1111
    if(c=='-')  //- means this block has 2 doors — to the left and to the right neighbours;
        return 5;  //0101
    if(c=='|')  //| means this block has 2 doors — to the top and to the bottom neighbours;
        return 10;   //1010
    if(c=='^')  //^ means this block has 1 door — to the top neighbour;
        return 8;   //1000
    if(c=='>')  //> means this block has 1 door — to the right neighbour;
        return 4;   //0100
    if(c=='<')  //< means this block has 1 door — to the left neighbour;
        return 1;   //0001
    if(c=='v')  //v means this block has 1 door — to the bottom neighbour;
        return 2;   //0010
    if(c=='L')  //L means this block has 3 doors — to all neighbours except left one;
        return 14;  //1110
    if(c=='R')  //R means this block has 3 doors — to all neighbours except right one;
        return 11;  //1011
    if(c=='U')  //U means this block has 3 doors — to all neighbours except top one;
        return 7;   //0111
    if(c=='D')  //D means this block has 3 doors — to all neighbours except bottom one;
        return 13;  //1101
    if(c=='*')  //* means this block is a wall and has no doors.
        return 0;   //0000
}

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

int bfs()
{
    memset(vis,0,sizeof(vis));
    queue <Node> q;
    Node now,next;
    now.x=sx;
    now.y=sy;
    now.step=0;
    now.status=0;
    q.push(now);
    vis[now.x][now.y][now.status]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==ex && now.y==ey)
            return now.step;
        if(!vis[now.x][now.y][(now.status+1)%4])    //原地不动的情况
        {
            Node temp;
            temp.x=now.x;
            temp.y=now.y;
            temp.step=now.step+1;
            temp.status=(now.status+1)%4;
            q.push(temp);
            vis[temp.x][temp.y][temp.status]=1;
        }
        for(int i=0; i<4; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            if(maze[next.x][next.y])
            {
                next.status=now.status;
                //cout << (maze[now.x][now.y] & (1<<(i+next.status)%4)) << "#" << (maze[now.x][now.y] & (1<<(i+2+next.status)%4)) << endl;
                //cout << next.x << " " << next.y << " " << next.status << endl;
                if(inMap(next.x,next.y) && (maze[now.x][now.y] & (1<<(i+next.status)%4)) && (maze[next.x][next.y] & (1<<(i+next.status+2)%4)))
                {
                    if(!vis[next.x][next.y][next.status])
                    {
                        next.step=now.step+1;
                        q.push(next);
                        //cout << next.x << " " << next.y << " " << next.step << " " << next.status << endl;
                        vis[next.x][next.y][next.status]=1;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&n,&m);
    char str[MAXN];
    for(int i=1; i<=n; i++)
    {
        scanf("%s",str+1);
        for(int j=1; j<=m; j++)
        {
            //printf("%c",str[j]);
            maze[i][j]=getStatus(str[j]);
            //printf("%d",maze[i][j]);
        }
        //puts("");
    }
    scanf("%d%d",&sx,&sy);
    scanf("%d%d",&ex,&ey);
    printf("%d\n",bfs());
    return 0;
}
