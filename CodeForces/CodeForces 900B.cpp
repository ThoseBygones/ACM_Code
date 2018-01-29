#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int ans=-1;
    int cnt=0;
    int pre=-1;
    while(cnt<=1e5)
    {
        cnt++;
        a*=10;
        if(a/b==c)
        {
            ans=cnt;
            break;
        }
        a%=b;
    }
    printf("%d\n",ans);
    return 0;
}
