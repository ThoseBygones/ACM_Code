#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Plate
{
    int x;  //列
    int y;  //行
    int z;  //层
};

char grid[15][15][15];  //层、列、行
int vis[15][15][15];
int dx[]={-1,1,0,0,0,0};
int dy[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,1,-1};
int k,n,m;

bool inMap(int x,int y,int z)
{
    if(x>=0 && x<n && y>=0 && y<m && z>=0 && z<k)
        return true;
    return false;
}

int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int l=0; l<k; l++)
    {
        for(int i=0; i<n; i++)
            scanf("%s",grid[l][i]);
    }
    int sum=0;
    queue <Plate> q;
    int sx,sy;
    scanf("%d%d",&sx,&sy);
    sx--;
    sy--;
    Plate temp;
    temp.x=sx;
    temp.y=sy;
    temp.z=0;
    q.push(temp);
    vis[temp.z][temp.x][temp.y]=1;
    sum++;
    while(!q.empty())
    {
        Plate cur,next;
        cur=q.front();
        q.pop();
        for(int i=0; i<6; i++)
        {
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            int nz=cur.z+dz[i];
            if(inMap(nx,ny,nz) && !vis[nz][nx][ny] && grid[nz][nx][ny]=='.')
            {
                next.x=nx;
                next.y=ny;
                next.z=nz;
                q.push(next);
                vis[nz][nx][ny]=1;
                sum++;
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
