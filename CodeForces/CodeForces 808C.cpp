#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

struct Cup
{
    int id;
    int m;
    int t;
} cup[MAXN];

int a[MAXN];

int cmp1(Cup a,Cup b)
{
    return a.m>b.m;
}

int cmp2(Cup a,Cup b)
{
    return a.id<b.id;
}

int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&cup[i].m);
        cup[i].id=i;
        cup[i].t=(cup[i].m+1)>>1;   //保证每个杯子至少能倒到一半以上
        sum+=cup[i].t;
    }
    sort(cup+1,cup+1+n,cmp1);
    for(int i=1; i<=n; i++)
    {
        while(sum<w && cup[i].t<cup[i].m)
        {
            sum++;
            cup[i].t++;
        }
    }
    sort(cup+1,cup+1+n,cmp2);
    if(sum==w)
    {
        for(int i=1; i<n; i++)
            printf("%d ",cup[i].t);
        printf("%d\n",cup[n].t);
    }
    else
        puts("-1");
    return 0;
}
