#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define INF 1e9

int main()
{
    int n,a;
    scanf("%d%d",&n,&a);
    double ans=INF;
    double p=180.0/n;
    int cnt=-1;
    for(int i=1; i<=n-2; i++)
    {
        if(fabs(ans-a)>fabs(p*i-a))
        {
            ans=p*i;
            cnt=i;
        }
    }
    printf("%d %d %d\n",n-cnt,1,n);
    return 0;
}
