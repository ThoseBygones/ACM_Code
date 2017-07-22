//尺取法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

int a[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,s;
        scanf("%d%d",&n,&s);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int l=0,r=0,sum=0;
        int res=n+1;
        while(true)
        {
            while(r<n && sum<s)
            {
                sum+=a[r];
                r++;
            }
            if(sum<s)
                break;
            res=min(res,r-l);
            sum-=a[l];
            l++;
        }
        if(res>n)
            puts("0");
        else
            printf("%d\n",res);
    }
    return 0;
}
