#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char tun[3][110];
int vis[3][110];
int n,k;
bool flag;  //判断是否能成功走出隧道的标志

bool inMap(int x)
{
    if(x>=0 && x<=2)
        return true;
    return false;
}

void dfs(int x,int y)
{
    vis[x][y]=1;
    if(y>=n)
    {
        flag=true;
        return ;
    }
    if(tun[x][y+1]!='.')
        return ;
    if(inMap(x-1) && !vis[x-1][y+3])
    {
        if(tun[x-1][y+1]=='.' && tun[x-1][y+2]=='.' && tun[x-1][y+3]=='.')
            dfs(x-1,y+3);
    }
    if(inMap(x+1) && !vis[x+1][y+3])
    {
        if(tun[x+1][y+1]=='.' && tun[x+1][y+2]=='.' && tun[x+1][y+3]=='.')
            dfs(x+1,y+3);
    }
    if(!vis[x][y+3])
    {
        if(tun[x][y+1]=='.' && tun[x][y+2]=='.' && tun[x][y+3]=='.')
            dfs(x,y+3);
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<3; i++)
            cin >> tun[i];
        for(int i=0; i<3; i++)
        {
            for(int j=n; j<n+5; j++)
                tun[i][j]='.';
        }
        flag=false;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(tun[i][j]=='s')
                {
                    dfs(i,j);
                    break;
                }
            }
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
