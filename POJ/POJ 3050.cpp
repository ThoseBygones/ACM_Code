#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

set <string> s;

int hop[10][10];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
string temp;

bool inMap(int x,int y)
{
    if(x>=1 && x<=5 && y>=1 && y<=5)
        return true;
    return false;
}

void dfs(int x,int y,int step)
{
    if(step==5)
    {
        s.insert(temp);
        return ;
    }
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny))
        {
            temp.push_back(hop[nx][ny]+'0');
            dfs(nx,ny,step+1);
            temp=temp.substr(0,temp.size()-1);
        }
    }
}

int main()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
            scanf("%d",&hop[i][j]);
    }
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
        {
            temp=hop[i][j]+'0';
            dfs(i,j,0);
        }
    }
    printf("%d\n",s.size());
    return 0;
}
