#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

char s[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int x=0,y=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='U')
            y++;
        if(s[i]=='D')
            y--;
        if(s[i]=='L')
            x--;
        if(s[i]=='R')
            x++;
    }
    printf("%d\n",n-abs(x)-abs(y));
    return 0;
}
