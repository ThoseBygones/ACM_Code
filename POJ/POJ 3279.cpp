#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 20
using namespace std;

int a[MAXN][MAXN],flip[MAXN][MAXN],ans[MAXN][MAXN];
int m,n;
int dx[]={0,-1,0,1,0};
int dy[]={0,0,-1,0,1};

int dfs(int x,int y)
{
    int status=a[x][y]; //初始需要翻转的次数
    for(int i=0; i<5; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<m && ny>=0 && ny<n)
            status+=flip[nx][ny];
    }
    return status&1;    //总需要翻转的次数等于(初始+它的上下左右需要翻转的次数)%2
}

int cal()
{
    for(int i=1; i<m; i++)
    {
        for(int j=0; j<n; j++)  //（i-1,j)为黑色，则反转（i,j)
        {
            if(dfs(i-1,j))
                flip[i][j]=1;
        }
    }
    for(int j=0; j<n; j++)  //最后一行还有黑色的，则无解
    {
        if(dfs(m-1,j))
            return INF;
    }
    int res=0;  //翻转次数
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            res+=flip[i][j];
    }
    return res;
}

int main()
{
    while(cin >> m >> n)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                cin >> a[i][j];
        }
        int cnt=INF;
        for(int i=0; i<(1 << n); i++)   //枚举第一行的翻转情况
        {
            memset(flip,0,sizeof(flip));
            for(int j=0; j<n; j++)
                flip[0][j]=(i >> j)&1;
            int temp=cal();
            if(temp<cnt)
            {
                cnt=temp;
                for(int j=0; j<m; j++)
                {
                    for(int k=0; k<n; k++)
                        ans[j][k]=flip[j][k];
                }
            }
        }
        if(cnt==INF)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cout << ans[i][j];
                    if(j!=n-1)
                        cout << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
