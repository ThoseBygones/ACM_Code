#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int n,t,k,d;
    scanf("%d%d%d%d",&n,&t,&k,&d);
    int t1=0,t2=0,tt=0;
    int temp=(n%k?(n/k+1):n/k);
    t1=temp*t;
    if(temp*t<=d)
        t2=d;
    else
    {
        t2=d;
        tt=d/t*t;
        temp-=d/t;
        if(temp%2)
            t2=tt+(temp/2+1)*t;
        else
            t2+=temp/2*t;
    }
    if(t1>t2)
        puts("YES");
    else
        puts("NO");
}
