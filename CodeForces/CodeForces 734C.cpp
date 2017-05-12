#include <iostream>
#include <algorithm>
#define LL long long
#define MAXN 200005
using namespace std;

LL n,m,k,s,x;
LL a[MAXN],b[MAXN],c[MAXN],d[MAXN];

int main()
{
    cin >> n >> m >> k;
    cin >> x >> s;
    for(int i=0; i<m; i++)
        cin >> a[i];
    for(int i=0; i<m; i++)
        cin >> b[i];
    for(int i=0; i<k; i++)
        cin >> c[i];
    for(int i=0; i<k; i++)
        cin >> d[i];
    LL ans=(n-c[upper_bound(d,d+k,s)-d-1])*x;
    for(int i=0; i<m; i++)
    {
        if(b[i]<=s)
            ans=min(ans,(LL)(n-c[upper_bound(d,d+k,s-b[i])-d-1])*a[i]);
    }
    cout << ans << endl;
    return 0;
}


#include <iostream>
#include <algorithm>
#define LL long long
#define MAXN 200005
using namespace std;

LL n,m,k,s,x;
LL a[MAXN],b[MAXN],c[MAXN],d[MAXN];

int biSearch(int value)
{
    int left=1,right=k,res=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(d[mid]<=value)
        {
            res=mid;
            left=mid+1;
        }
        else
            right=mid-1;
    }
    return res;
}

int main()
{
    cin >> n >> m >> k;
    cin >> x >> s;
    for(int i=1; i<=m; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> b[i];
    for(int i=1; i<=k; i++)
        cin >> c[i];
    for(int i=1; i<=k; i++)
        cin >> d[i];
    LL ans=(n-c[biSearch(s)])*x;
    for(int i=1; i<=m; i++)
    {
        if(b[i]<=s)
            ans=min(ans,(LL)(n-c[biSearch(s-b[i])])*a[i]);
    }
    cout << ans << endl;
    return 0;
}
