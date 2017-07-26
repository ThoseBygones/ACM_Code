#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int l[5],s[5],r[5],p[5];

int main()
{
    for(int i=1; i<=4; i++)
        scanf("%d%d%d%d",&l[i],&s[i],&r[i],&p[i]);
    if(p[1]==1)
    {
        if(l[1] || s[1] || r[1] || l[2] || s[3] || r[4])
        {
            puts("YES");
            return 0;
        }
    }
    if(p[2]==1)
    {
        if(l[2] || s[2] || r[2] || l[3] || s[4] || r[1])
        {
            puts("YES");
            return 0;
        }
    }
    if(p[3]==1)
    {
        if(l[3] || s[3] || r[3] || l[4] || s[1] || r[2])
        {
            puts("YES");
            return 0;
        }
    }
    if(p[4]==1)
    {
        if(l[4] || s[4] || r[4] || l[1] || s[2] || r[3])
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
