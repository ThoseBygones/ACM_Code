#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

char c;
int n,m;
char room[105][105];
int vis[105][105];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
map <char,bool> office;

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void dfs(int x,int y)
{
    if(vis[x][y])
        return;
    vis[x][y]=true;
    for(int i=0; i<4; i++)
    {
        if(inMap(x+dx[i],y+dy[i]) && room[x+dx[i]][y+dy[i]]!='.')
        {
            if(room[x+dx[i]][y+dy[i]]!=c)
                office[room[x+dx[i]][y+dy[i]]]=true;
            else
                dfs(x+dx[i],y+dy[i]);

        }
    }
}

int main()
{
    int x,y;
    while(cin >> n >> m >> c)
    {
        memset(vis,0,sizeof(vis));
        office.clear();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> room[i][j];
                if(room[i][j]==c)
                {
                    x=i;
                    y=j;
                }
            }
        }
        dfs(x,y);
        cout << office.size() << endl;
    }
    return 0;
}
