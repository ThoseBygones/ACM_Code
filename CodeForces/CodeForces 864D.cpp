#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

priority_queue <int,vector<int>,greater<int> > pq;

int a[MAXN];
int vis[MAXN];
int has[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    memset(vis,0,sizeof(vis));
    memset(has,0,sizeof(has));
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            pq.push(i);
            cnt++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[a[i]]>1)
        {
            int t=pq.top();
            if(t<a[i] || has[a[i]])
            {
                vis[a[i]]--;
                a[i]=t;
                pq.pop();
            }
            else
                has[a[i]]=1;
        }
    }
    printf("%d\n",cnt);
    for(int i=1; i<n; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
    return 0;
}
