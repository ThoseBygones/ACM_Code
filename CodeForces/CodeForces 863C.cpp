#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long
#define MP make_pair
#define PB push_back

typedef pair<LL, LL> PLL;

LL ma[5][5],mb[5][5];
LL w[5][5];
LL vis[5][5];
PLL dp[5][5];

int main()
{
    LL k,a,b;
    scanf("%I64d%I64d%I64d",&k,&a,&b);
    w[1][3]=w[2][1]=w[3][2]=1;
    k--;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
            scanf("%I64d",&ma[i][j]);
    }
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
            scanf("%I64d",&mb[i][j]);
    }
    LL cnt=0;
    LL ans1=w[a][b],ans2=w[b][a];
    while(k)
    {
        k--;
        cnt++;
        LL ta=ma[a][b],tb=mb[a][b];
        ans1+=w[ta][tb];
        ans2+=w[tb][ta];
        if(vis[ta][tb]) //循环节已经找到
        {
            LL len=cnt-vis[ta][tb];
            LL d=k/len;
            k%=len;
            ans1+=1LL*d*(ans1-dp[ta][tb].first);
            ans2+=1LL*d*(ans2-dp[ta][tb].second);
            a=ta,b=tb;
            break;
        }
        else
        {
            a=ta,b=tb;
            vis[a][b]=cnt;
            dp[a][b]=MP(ans1,ans2);
        }
    }
    while(k)
    {
        k--;
        LL ta=ma[a][b],tb=mb[a][b];
        ans1+=w[ta][tb];
        ans2+=w[tb][ta];
        a=ta,b=tb;
    }
    printf("%I64d %I64d\n",ans1,ans2);
    return 0;
}
