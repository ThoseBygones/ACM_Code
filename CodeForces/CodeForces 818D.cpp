#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int cnt[MAXN];

int main()
{
    int n,a,x;
    scanf("%d%d",&n,&a);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        if(x==a)
            cnt[a]++;
        else
        {
            if(cnt[x]>=cnt[a])
                cnt[x]++;
        }
    }
    for(int i=1; i<=1000000; i++)
    {
        if(i!=a && cnt[i]>=cnt[a])
        {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
