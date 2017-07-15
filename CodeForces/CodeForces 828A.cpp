#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int main()
{
    int n,a,b,c;
    int x;
    int ans=0;
    scanf("%d%d%d",&n,&a,&b);
    c=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            if(a)
                a--;
            else if(b)
            {
                b--;
                c++;
            }
            else if(c)
                c--;
            else
                ans++;
        }
        else if(x==2)
        {
            if(b)
                b--;
            else
                ans+=2;
        }
    }
    printf("%d\n",ans);
    return 0;
}
