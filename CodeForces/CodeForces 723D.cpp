#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char mp[55][55];
bool vis[55][55];
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int n,m,k;
int lakeSize,fillNum;
bool isLake;

struct Lake
{
    int x;
    int y;
    int num;
} lake;

vector <Lake> vl;

bool cmp(Lake a,Lake b)
{
    return a.num<b.num;
}

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void dfs(int x,int y)
{
    vis[x][y]=1;
    lakeSize++;
    if(x<=0 || x>=n-1 || y<=0 || y>=m-1)
        isLake=false;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny) && mp[nx][ny]=='.' && !vis[nx][ny])
            dfs(nx,ny);
    }
}

void fillLake(int x,int y)
{
    vis[x][y]=1;
    fillNum++;
    mp[x][y]='*';
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny) && mp[nx][ny]=='.' && !vis[nx][ny])
            fillLake(nx,ny);
    }
}

int main()
{
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> mp[i];
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mp[i][j]=='.' && !vis[i][j])
            {
                lakeSize=0;
                isLake=true;
                dfs(i,j);
                if(isLake)
                    vl.push_back((Lake){i,j,lakeSize});
            }
        }
    }
    memset(vis,0,sizeof(vis));
    sort(vl.begin(),vl.end(),cmp);
    //cout << vl.size() << endl;
    for(int cnt=0; cnt<vl.size()-k; cnt++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==vl[cnt].x && j==vl[cnt].y)
                    fillLake(i,j);
            }
        }
    }
    cout << fillNum << endl;
    for(int i=0; i<n; i++)
        cout << mp[i] << endl;
    return 0;
}
