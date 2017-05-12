#include <iostream>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXN 1<<24
using namespace std;

int x[25],y[25];
int dis[25][25];
int pre[MAXN],dp[MAXN];
int ans[50];

int main()
{
    ios::sync_with_stdio(false);
    int x0,y0,n;
    cin >> x0 >> y0;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];
    x[n]=x0;
    y[n]=y0;
    for(int i=0; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
            dis[i][j]=dis[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    }
    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    for(int i=0; i<(1 << n); i++)   //遍历24种状态
    {
        if(dp[i]!=INF)
        {
            for(int j=0; j<n; j++)  //遍历24个点
            {
                if(!(i&(1<<j)))
                {
                    int temp=i|(1<<j);
                    int len=dp[i]+dis[n][j]+dis[j][n];
                    if(dp[temp]>len)
                    {
                        dp[temp]=len;
                        pre[temp]=i;
                    }
                    for(int k=j+1; k<n; k++)
                    {
                        if(!(temp&(1<<k)))
                        {
                            int pts=temp|(1<<k);
                            len=dp[i]+dis[n][j]+dis[j][k]+dis[k][n];
                            if(dp[pts]>len)
                            {
                                dp[pts]=len;
                                pre[pts]=i;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    vector <int> ans;
    int x=(1<<n)-1;
    cout << dp[x] << endl;
    ans.push_back(0);
    while(x)
    {
        int p=pre[x];
        int temp=p^x;
        for(int i=0; i<n; i++)
        {
            if(temp&(1<<i))
                ans.push_back(i+1);
        }
        ans.push_back(0);
        x=p;
    }
    for(int i=0; i<ans.size()-1; i++)
        cout << ans[i] << " ";
    cout << ans[ans.size()-1] << endl;
    return 0;
}
