//使用map或者vis数组都能过，但是使用map慢很多
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define MAXN 505

struct Point
{
    int x;
    int y;
} p[MAXN];

int vis[510][510];

int inRange(int x,int y)
{
    if(x>=-100 && x<=100 && y>=-100 && y<=100)
        return true;
    return false;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        //map <pair<int,int>,int> h;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            //h[make_pair(p[i].x,p[i].y)]=1;
            vis[p[i].x+100][p[i].y+100]=1;
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int ax=p[i].x-(p[j].y-p[i].y);
                int ay=p[i].y+(p[j].x-p[i].x);
                int bx=p[j].x-(p[j].y-p[i].y);
                int by=p[j].y+(p[j].x-p[i].x);
                //if(inRange(ax,ay) && inRange(bx,by) && h[make_pair(ax,ay)] && h[make_pair(bx,by)])
                if(inRange(ax,ay) && inRange(bx,by) && vis[ax+100][ay+100] && vis[bx+100][by+100])
                    cnt++;
                int cx=p[i].x+(p[j].y-p[i].y);
                int cy=p[i].y-(p[j].x-p[i].x);
                int dx=p[j].x+(p[j].y-p[i].y);
                int dy=p[j].y-(p[j].x-p[i].x);
                //if(inRange(cx,cy) && inRange(dx,dy) && h[make_pair(cx,cy)] && h[make_pair(dx,dy)])
                if(inRange(cx,cy) && inRange(dx,dy) && vis[cx+100][cy+100] && vis[dx+100][dy+100])
                    cnt++;
            }
        }
        printf("%d\n",cnt/4);
    }
    return 0;
}
