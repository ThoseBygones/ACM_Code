#include <iostream>
#include <cstring>
using namespace std;

char puz[55][55];
int dx[]= {0,-1,-1,-1,0,1,1,1};
int dy[]= {-1,-1,0,1,1,1,0,-1};
int m,n;
int cnt;
char str[55];

char trans(char c)
{
    if(c>='A' && c<='Z')
        c+=32;
    else if(c>='a' && c<='z')
        c-=32;
    return c;
}

bool inMap(int x,int y)
{
    if(x>=1 && x<=m && y>=1 && y<=n)
        return true;
    return false;
}

void dfs(int x,int y,int k)
{
    if(!str[cnt])
        return ;
    int nx=x+dx[k];
    int ny=y+dy[k];
    if(inMap(nx,ny) && (puz[nx][ny]==str[cnt] || puz[nx][ny]==trans(str[cnt])))
    {
        //cout << cnt << endl;
        //cout << nx << " " << ny << endl;
        //cout << puz[nx][ny] << endl;
        cnt++;
        dfs(nx,ny,k);
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for(int i=1; i<=m; i++)
            cin >> puz[i]+1;
        int kase;
        cin >> kase;
        while(kase--)
        {
            memset(str,0,sizeof(str));
            cin >> str;
            //cout << str;
            bool flag=false;
            for(int i=1; i<=m; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(puz[i][j]==str[0] || puz[i][j]==trans(str[0]))
                    {
                        for(int k=0; k<8; k++)
                        {
                            cnt=1;
                            dfs(i,j,k);
                            if(cnt==strlen(str))
                            {
                                cout << i << " " << j << endl;
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(flag)
                        break;
                }
                if(flag)
                    break;
            }
        }
        if(t)
            cout << endl;
    }
    return 0;
}
