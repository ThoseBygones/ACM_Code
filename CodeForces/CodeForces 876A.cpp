#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int n,a,b,c;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    if(n==1)
        puts("0");
    else if(n==2)
        printf("%d\n",min(a,b));
    else
    {
        if(min(a,b)>c)
            printf("%d\n",(n-2)*c+min(a,b));
        else
            printf("%d\n",(n-1)*min(a,b));
    }
    return 0;
}
