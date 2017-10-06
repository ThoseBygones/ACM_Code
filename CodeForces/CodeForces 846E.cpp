//树形dp
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long
#define PII pair
#define MP make_pair
#define PB push_back

typedef double Type;    //注意会爆LL，因此用double

Type a[MAXN];
Type b[MAXN];
Type dp[MAXN];

vector < PII<Type,Type> > g[MAXN];

void dfs(int u)
{
    dp[u]=b[u]-a[u];
    for(int i=0; i<g[u].size(); i++)
    {
        int k=g[u][i].first;
        int v=g[u][i].second;
        dfs(v);
        if(dp[v]<0) //现有材料量无法满足需求
            dp[u]+=dp[v]*k;
        else
            dp[u]+=dp[v];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> b[i];
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=2; i<=n; i++)
    {
        int x,k;
        cin >> x >> k;
        g[x].PB(MP(k,i));
    }
    dfs(1);
    if(dp[1]>=0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
