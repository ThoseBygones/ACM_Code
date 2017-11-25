#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int n;
    LL k;
    scanf("%d%I64d",&n,&k);
    bool first=true;
    int ans=0;
    LL cnt=0;
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        if(first)
        {
            first=false;
            ans=x;
            continue;
        }
        if(x<ans)
            cnt++;
        else
            cnt=1;
        ans=max(x,ans);
        if(cnt>=k)
            break;
    }
    printf("%d\n",ans);
    return 0;
}
