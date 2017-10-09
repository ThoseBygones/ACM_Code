#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int a[MAXN];
int t[MAXN];
int l[MAXN];
int r[MAXN];

int main()
{
    int n,q,m;
    scanf("%d%d%d",&n,&q,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=q; i++)
        scanf("%d%d%d",&t[i],&l[i],&r[i]);
    while(m--)
    {
        int val;
        scanf("%d",&val);
        for(int i=q; i; i--)
        {
            if(l[i]<=val && val<=r[i])
            {
                if(t[i]==1)
                    val=val==l[i]?r[i]:val-1;
                else
                    val=l[i]+r[i]-val;
            }
        }
        printf("%d ",a[val]);
    }
    puts("");
    return 0;
}
