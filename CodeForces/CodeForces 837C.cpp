#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int x[MAXN],y[MAXN];

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0; i<n; i++)
        scanf("%d%d",&x[i],&y[i]);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(max(x[i],x[j])<=a && y[i]+y[j]<=b)
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
            if(max(x[i],y[j])<=a && y[i]+x[j]<=b)
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
            if(max(y[i],x[j])<=a && x[i]+y[j]<=b)
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
            if(max(y[i],y[j])<=a && x[i]+x[j]<=b)
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
            if(max(x[i],x[j])<=b && y[i]+y[j]<=a)
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
            if(max(x[i],y[j])<=b && y[i]+x[j]<=a)
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
            if(max(y[i],x[j])<=b && x[i]+y[j]<=a)
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
            if(max(y[i],y[j])<=b && x[i]+x[j]<=a)
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
