#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

struct TShirt
{
    int p,a,b;
} t[MAXN];

set <int> s[5];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&t[i].p);
    for(int i=1; i<=n; i++)
        scanf("%d",&t[i].a);
    for(int i=1; i<=n; i++)
        scanf("%d",&t[i].b);
    for(int i=1; i<=n; i++)
    {
        s[t[i].a].insert(t[i].p);
        s[t[i].b].insert(t[i].p);
    }
    int m;
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
    {
        int temp;
        scanf("%d",&temp);
        if(s[temp].size())
        {
            int res=*(s[temp].begin());
            if(i!=m)
                printf("%d ",res);
            else
                printf("%d\n",res);
            for(int i=1; i<=3; i++)
                s[i].erase(res);
        }
        else
        {
            if(i!=m)
                printf("-1 ");
            else
                printf("-1\n");
        }
    }
    return 0;
}
