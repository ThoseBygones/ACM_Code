#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int m,d;
    scanf("%d%d",&m,&d);
    int left=day[m]+d-8;
    int ans=0;
    if(left%7==0)
        ans=left/7+1;
    else
        ans=left/7+2;
    printf("%d\n",ans);
    return 0;
}
