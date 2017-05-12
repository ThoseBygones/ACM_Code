#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

#define MAXN 105

int a[MAXN];    //Interesting points of each city
int pre[MAXN];  //The previous city Weiwei traveled according to his current city
int edge[MAXN][MAXN];   //adjacent matrix
int dp[MAXN];   //The interesting points Weiwei can get from city 1 to the city i

int main()
{
    int t,n,m;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        memset(edge,0,sizeof(edge));
        memset(pre,0,sizeof(pre));
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        a[n+1]=0;   //Consider Hangzhou to be the n+1 city and its interesting points is 0
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u][v]=1;
        }
        for(int i=1; i<=n+1; i++)
        {
            for(int j=1; j<i; j++)
            {
                if(edge[j][i])
                {
                    if(dp[i]<dp[j]+a[i])
                    {
                        dp[i]=dp[j]+a[i];
                        pre[i]=j;
                    }
                }
            }
        }
        stack <int> s;
        int temp=pre[n+1];
        while(temp)
        {
            s.push(temp);
            temp=pre[temp];
        }
        printf("CASE %d#\npoints : %d\ncircuit : ",kase++,dp[n+1]);
        while(!s.empty())
        {
            printf("%d->",s.top());
            s.pop();
        }
        printf("1\n");
        if(t)
            puts("");
    }
    return 0;
}
