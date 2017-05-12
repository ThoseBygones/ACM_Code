#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

int main()
{
    int xa,ya,xb,yb,xc,yc;
    while(~scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc))
    {
        puts("3");
        printf("%d %d\n",xc+(xb-xa),yc+(yb-ya));
        printf("%d %d\n",xb+(xa-xc),yb+(ya-yc));
        printf("%d %d\n",xa+(xc-xb),ya+(yc-yb));
    }
    return 0;
}
