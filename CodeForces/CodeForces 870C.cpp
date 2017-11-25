#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        if(n%4==0)
            ans=n/4;
        else if(n%4==1)
        {
            if(n/4>=2)
                ans=n/4-1;
            else
                ans=-1;
        }
        else if(n%4==2)
        {
            if(n/4>=1)
                ans=n/4;
            else
                ans=-1;
        }
        else
        {
            if(n/4>=3)
                ans=n/4-1;
            else
                ans=-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
