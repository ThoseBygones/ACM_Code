#include <bits/stdc++.h>
using namespace std;

#define MAXN 15

int vis[MAXN];
int a[MAXN],b[MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        vis[a[i]]=1;
    }
    for(int i=0; i<m; i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0; i<m; i++)
    {
        if(vis[b[i]])
        {
            printf("%d\n",b[i]);
            return 0;
        }
    }
    printf("%d%d\n",min(a[0],b[0]),max(a[0],b[0]));
    return 0;
}
