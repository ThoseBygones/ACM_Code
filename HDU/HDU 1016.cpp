#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define LL long long
#define MAXN 1005
#define INF 0x3f3f3f3f
#define MOD 1000000007

int prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41};
int ans[55];
int vis[55];
int n;

bool isPrime(int x)
{
    for(int i=0; i<13; i++)
    {
        if(x==prime[i])
            return true;
    }
    return false;
}

void print()
{
    for(int i=1; i<n; i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}

void dfs(int step)
{
    if(step==n+1 && isPrime(ans[n]+ans[1]))
    {
        print();
        return ;
    }
    for(int i=2; i<=n; i++)
    {
        if(!vis[i] && isPrime(i+ans[step-1]))
        {
            ans[step]=i;
            vis[i]=true;
            dfs(step+1);
            vis[i]=false;   //还原现场
        }
    }
}

int main()
{
    int kase=1;
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        ans[1]=1;
        printf("Case %d:\n",kase++);
        dfs(2);
        puts("");
    }
    return 0;
}
