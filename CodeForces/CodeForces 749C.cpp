#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 200005

char str[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    queue <int> qd,qr;
    for(int i=1; i<=n; i++)
    {
        if(str[i]=='D')
            qd.push(i);
        if(str[i]=='R')
            qr.push(i);
    }
    while(!qd.empty() && !qr.empty())
    {
        int d,r;
        d=qd.front();
        r=qr.front();
        qd.pop();
        qr.pop();
        if(d<r)
            qd.push(d+n);
        else
            qr.push(r+n);
    }
    if(!qd.empty())
        puts("D");
    else if(!qr.empty())
        puts("R");
    return 0;
}
