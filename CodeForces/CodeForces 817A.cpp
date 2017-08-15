#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int x1,y1,x2,y2,x,y;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x,&y);
    if(abs(x1-x2)%x || abs(y1-y2)%y)
        puts("NO");
    else
    {
        if((abs(x1-x2)/x)%2==(abs(y1-y2)/y)%2)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
