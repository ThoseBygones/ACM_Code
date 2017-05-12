#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005

int n;
int a[MAXN];

int main()
{
    while(~scanf("%d",&n))
    {
        int cnt=1;
        if(n%2)
        {
            n-=3;
            a[cnt++]=3;
        }
        else
        {
            n-=2;
            a[cnt++]=2;
        }
        while(n)
        {
            n-=2;
            a[cnt++]=2;
        }
        printf("%d\n",cnt-1);
        for(int i=1; i<cnt; i++)
            printf("%d ",a[i]);
        puts("");
    }
    return 0;
}
