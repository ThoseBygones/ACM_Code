#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define LL long long

LL a[MAXN],b[MAXN];
vector <LL> v;

int main()
{
    LL x,y,l,r;
    scanf("%I64d%I64d%I64d%I64d",&x,&y,&l,&r);
    a[0]=b[0]=1;
    int p,q;
    for(p=0; a[p]<=r/x; p++)
        a[p+1]=a[p]*x;
    for(q=0; b[q]<=r/y; q++)
        b[q+1]=b[q]*y;
    for(int i=0; i<=p; i++)
    {
        for(int j=0; j<=q; j++)
        {
            if(a[i]+b[j]>=l && a[i]+b[j]<=r)
                v.push_back(a[i]+b[j]);
        }
    }
    v.push_back(l-1);
    v.push_back(r+1);
    sort(v.begin(),v.end());
    LL ans=0;
    for(int i=1; i<v.size(); i++)
        ans=max(ans,v[i]-v[i-1]-1);
    printf("%I64d\n",ans);
    return 0;
}
