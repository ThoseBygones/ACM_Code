#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 1000010

int num[MAXN];
int vis[MAXN];

void solve()
{
    for(int i=0; i<MAXN; i++)
        vis[i]=0;
    for(int i=5; i<MAXN; i+=4)
    {
        for(int j=5; j<MAXN && i*j<MAXN; j+=4)
        {
            if(!vis[i] && !vis[j])
                vis[i*j]=1;
            else
                vis[i*j]=-1;
        }
    }
    int cnt=0;
    for(int i=1; i<MAXN; i++)
    {
        if(vis[i]==1)
            cnt++;
        num[i]=cnt;
    }
}

int main()
{
    solve();
    int n;
    while(~scanf("%d",&n),n)
        printf("%d %d\n",n,num[n]);
    return 0;
}
