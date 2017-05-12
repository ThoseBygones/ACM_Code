#include <iostream>
#include <cstring>
#define MAXN 105
using namespace std;

char land[MAXN][MAXN];
int vis[MAXN][MAXN];
int n,m;
int cnt;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,-1,-1,-1,0,1,1,1};

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0; i<8; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny) && land[nx][ny]=='W' && !vis[nx][ny])
            dfs(nx,ny);
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> land[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(land[i][j]=='W' && !vis[i][j])
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
