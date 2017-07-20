#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int dir[8][2]= {2,1,2,-1,-2,1,-2,-1,1,2,1,-2,-1,2,-1,-2};
int vis[10][10];

struct point
{
    int x;
    int y;
    int step;
};


int judge(int x,int y)
{
    if(x<0 || x>=8 || y<0 || y>=8)	return 0;
    if(vis[x][y])	return 0;
    return 1;
}
char str1[5],str2[5];

int bfs()
{
    queue<point>q;
    point cur,next;
    point start;
    int ex,ey;
    start.x=str1[1]-'1';
    start.y=str1[0]-'a';
    start.step=0;
    ex=str2[1]-'1';
    ey=str2[0]-'a';

    memset(vis,0,sizeof(vis));
    vis[start.x][start.y]=1;
    q.push(start);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.x==ex &&cur.y==ey)
            return cur.step;
        for(int i=0; i<8; i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if(next.x==ex && next.y==ey)
                return cur.step+1;
            if(judge(next.x,next.y)==0)
                continue;
            next.step=cur.step+1;
            vis[next.x][next.y]=1;
            q.push(next);
        }
    }
    return 0;
}


int main()
{
    int ans;
    while(cin >> str1 >> str2)
    {
        ans=bfs();
        printf("To get from %s to %s takes %d knight moves.\n",str1,str2,ans);
    }
    return 0;
}
