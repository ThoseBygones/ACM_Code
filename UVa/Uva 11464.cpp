#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 20
using namespace std;

int init[MAXN][MAXN],test[MAXN][MAXN],rec[MAXN];
int n,mmin;

void solve()
{
    int sum;
    for(int i=1; i<=n; i++)
        test[1][i]=rec[i];
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            sum=test[i-2][j]+test[i-1][j-1]+test[i-1][j+1];
            if(sum%2)
                test[i][j]=1;
            else
                test[i][j]=0;
        }
    }
}

int trans()
{
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(test[i][j]==0 && init[i][j]==1)
                return INF;
            if(test[i][j]==1 && init[i][j]==0)
                cnt++;
        }
    }
    return cnt;
}

void dfs(int x)
{
    if(x>n)
    {
        solve();
        int temp=trans();
        mmin=min(temp,mmin);
        return ;
    }
    rec[x]=0;
    dfs(x+1);
    rec[x]=1;
    dfs(x+1);
}

int main()
{
    int t,kase=1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(test,0,sizeof(test));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cin >> init[i][j];
        mmin=INF;
        dfs(1);
        cout << "Case " << kase++ << ": ";
        if(mmin==INF)
            cout << "-1" << endl;
        else
            cout << mmin << endl;
    }
    return 0;
}
