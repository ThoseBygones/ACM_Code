#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 100005

int f[MAXN];
int g[MAXN];
int h[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    int m=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&f[i]);
        if(i==f[i])
        {
            h[++m]=i;
            g[i]=m;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(f[i]==f[f[i]])
            g[i]=g[f[i]];
        else
        {
            puts("-1\n");
            return 0;
        }
    }
    printf("%d\n",m);
    for(int i=1; i<=n; i++)
        printf("%d ",g[i]);
    printf("\n");
    for(int i=1; i<=m; i++)
        printf("%d ",h[i]);
    printf("\n");
    return 0;
}
