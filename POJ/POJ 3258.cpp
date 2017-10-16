#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 50005

int a[MAXN];
int L,n,m;

int main()
{
    scanf("%d%d%d",&L,&n,&m);
    a[0]=0;
    a[n+1]=L;
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int l=0;
    int r=L;
    int cnt,pre;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        pre=a[0];
        cnt=0;
        for(int i=1; i<=n+1; i++)
        {
            if(a[i]-pre<=mid)
                cnt++;
            else
                pre=a[i];
        }
        if(cnt<=m)
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}
