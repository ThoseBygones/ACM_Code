#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int a[MAXN];    //前缀标记数组
int sum[MAXN];  //前缀和数组

int main()
{
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    for(int i=0; i<n; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        a[l]++;
        a[r+1]--;
    }
    int tot=0;
    int cnt=0;
    for(int i=1; i<=200000; i++)
    {
        tot+=a[i];
        if(tot>=k)
            cnt++;
        sum[i]=cnt;
    }
    for(int i=1; i<=q; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }
    return 0;
}
