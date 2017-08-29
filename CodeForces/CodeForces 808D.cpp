#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

LL a[MAXN];
LL suf[MAXN];   //前缀和
LL sum;

bool biSearch(int l,int r,LL val)
{
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(suf[mid]==val)
        {
            return true;
        }
        else if(suf[mid]<val)
            l=mid+1;
        else
            r=mid-1;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&a[i]);
        suf[i]=suf[i-1]+a[i];
        sum+=a[i];
    }
    if(sum&1)
    {
        puts("NO");
        return 0;
    }
    sum/=2;
    bool flag=false;
    int i=1;
    while(i<=n)
    {
        if(biSearch(0,i-1,sum-a[i]))
        {
            flag=true;
            break;
        }
        i++;
    }
    if(!flag)
    {
        i=1;
        while(i<n)
        {
            if(biSearch(i+1,n,sum+a[i]))
            {
                flag=true;
                break;
            }
            i++;
        }
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
