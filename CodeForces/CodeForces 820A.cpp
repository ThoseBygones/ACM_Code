#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int c,v0,v1,a,l;
    scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
    int sum=v0;
    int cnt=1;
    while(sum<c)
    {
        sum-=l;
        v0+=a;
        v0=min(v0,v1);
        sum+=v0;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
