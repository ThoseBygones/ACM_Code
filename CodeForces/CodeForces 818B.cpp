#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int l[MAXN];
int a[MAXN];
int vis[MAXN];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
        scanf("%d",&l[i]);
    for(int i=1; i<=n; i++)
    {
        vis[i]=0;
        a[i]=0;
    }
    for(int i=1; i<m; i++)
    {
        int temp=(l[i+1]-l[i]+n)%n;
        if(temp==0)
            temp=n;
        if((!vis[temp] && !a[l[i]]) || a[l[i]]==temp)
        {
            a[l[i]]=temp;
            vis[temp]=1;
        }
        else
        {
            puts("-1");
            return 0;
        }
    }
    int cnt=1;
    for(int i=1; i<=n; i++)
    {
        if(!a[i])
        {
            while(vis[cnt])
                cnt++;
            a[i]=cnt;
            vis[cnt]=1;
        }
    }
    for(int i=1; i<n; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
    return 0;
}
