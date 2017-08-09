//685ms
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define LL long long

map <LL,LL> mp;

int main()
{
    for(LL i=1; i<=1000000; i++)
        mp[i*i*i]=i;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        LL a,b;
        scanf("%I64d%I64d",&a,&b);
        LL res=a*b;
        LL c=mp[res];
        if(c && a%c==0 && b%c==0)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}


//280ms
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        LL a,b;
        scanf("%I64d%I64d",&a,&b);
        LL res=a*b;
        LL l=0,r=1000000;
        bool flag=false;
        int temp;
        while(l<=r)
        {
            LL mid=(l+r)/2;
            if(mid*mid*mid==res)
            {
                temp=mid;
                flag=true;
                break;
            }
            else if(mid*mid*mid<res)
                l=mid+1;
            else
                r=mid-1;
        }
        if(flag)
        {
            if(a%temp==0 && b%temp==0)
                puts("Yes");
            else
                puts("No");
        }
        else
            puts("No");
    }
    return 0;
}

