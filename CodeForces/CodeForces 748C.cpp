#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 200005

char s[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int cnt=1;
    int x=0,y=0;
    for(int i=1; i<=n; i++)
    {
        if(s[i]=='L')
        {
            if(x<=0)
                x=-1;
            else
            {
                cnt++;
                x=-1;
                y=0;
            }
        }
        if(s[i]=='U')
        {
            if(y>=0)
                y=1;
            else
            {
                cnt++;
                x=0;
                y=1;
            }
        }
        if(s[i]=='R')
        {
            if(x>=0)
                x=1;
            else
            {
                cnt++;
                x=1;
                y=0;
            }
        }
        if(s[i]=='D')
        {
            if(y<=0)
                y=-1;
            else
            {
                cnt++;
                x=0;
                y=-1;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
