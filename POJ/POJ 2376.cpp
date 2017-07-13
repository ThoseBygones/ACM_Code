#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 25005
#define INF 0x3f3f3f3f

struct Interval
{
    int l;
    int r;
} a[MAXN];

bool cmp(Interval a,Interval b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0; i<n; i++)
        scanf("%d%d",&a[i].l,&a[i].r);
    sort(a,a+n,cmp);
    a[n].l=INF;
    a[n].r=INF;
    int right=0;
    int tempR=0;
    bool flag=false;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(a[i].l<=right+1)
        {
            if(tempR<a[i].r)
            {
                tempR=a[i].r;
                flag=true;
            }
            if(a[i+1].l>right+1 && flag)
            {
                right=tempR;
                cnt++;
                flag=false;
            }
        }
    }
    if(right<t)
        puts("-1");
    else
        printf("%d\n",cnt);
    return 0;
}
