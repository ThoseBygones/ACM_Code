#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 100005
using namespace std;

int d[MAXN],a[MAXN],used[MAXN];
int n,m;

bool check(int x)
{
    memset(used,0,sizeof(used));
    int cur=x-1;
    for(int i=x; i>=1; i--)
    {
        cur=min(cur,i-1);
        if(d[i] && !used[d[i]] && a[d[i]]<=cur)
        {
            used[d[i]]=1;
            cur-=a[d[i]]+1;
        }
    }
    for(int i=1; i<=m; i++)
    {
        if(!used[i])
            return false;
    }
    return true;
}

int main()
{
    int ans=-1;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> d[i];
    for(int i=1; i<=m; i++)
        cin >> a[i];
    int l=1,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    cout << ans << endl;
    return 0;
}
