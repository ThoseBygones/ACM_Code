#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

char s[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int st,tg;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='G')
            st=i;
        if(s[i]=='T')
            tg=i;
    }
    int dir;
    if(st<tg)
        dir=1;
    else
        dir=-1;
    for(int i=st; ; i+=k*dir)
    {
        if((st<tg && i>tg) || (st>tg && i<tg) || s[i]=='#')
        {
            puts("NO");
            return 0;
        }
        if(s[i]==s[tg])
        {
            puts("YES");
            return 0;
        }
    }
    return 0;
}
