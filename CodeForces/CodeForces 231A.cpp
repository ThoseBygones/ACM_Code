#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    while(n--)
    {
        int cnt=0;
        for(int i=0; i<3; i++)
        {
            int x;
            scanf("%d",&x);
            cnt+=x;
        }
        if(cnt>=2)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
