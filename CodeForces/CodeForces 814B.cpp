#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int a[MAXN],b[MAXN];
int vis[MAXN];
vector <int> dif;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++)
        scanf("%d",&b[i]);
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
            dif.push_back(i);
        else
            vis[a[i]]=1;
    }
    if(dif.size()==1)
    {
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
                a[dif[0]]=i;
        }
        for(int i=0; i<n-1; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
    else
    {
        bool flag=true;
        vis[b[dif[0]]]=1;
        vis[a[dif[1]]]=1;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            a[dif[0]]=b[dif[0]];
            for(int i=0; i<n-1; i++)
                printf("%d ",a[i]);
            printf("%d\n",a[n-1]);
            return 0;
        }
        a[dif[1]]=b[dif[1]];
        for(int i=0; i<n-1; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
    return 0;
}
