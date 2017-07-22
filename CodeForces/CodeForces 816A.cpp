#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int h,m;

bool check(int h,int m)
{
    if(h/10+(h%10)*10==m)
        return true;
    return false;
}

int main()
{
    scanf("%d:%d",&h,&m);
    int ans=0;
    while(!check(h,m))
    {
        ans++;
        m++;
        if(m==60)
        {
            h++;
            m=0;
        }
        if(h==24)
            h=0;
    }
    printf("%d\n",ans);
}
