#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

//sum=val+id*k, that means the order you buy the souvenirs makes no sense -- you just need to decide which souvenirs to buy :)

struct Souvenirs
{
    LL val;
    LL id;
    LL sum;
    bool operator <(const Souvenirs &a) const
    {
        return sum<a.sum;
    }
} a[MAXN];

int main()
{
    int n;
    LL s;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i].val;
        a[i].id=i;
    }

    int cnt=0;
    LL ans=0;
    int l=0,r=n; //binary search the number of souvenirs to buy
    while(l<=r)
    {
        int mid=(l+r)>>1;
        for(int i=1; i<=n; i++)
            a[i].sum=(a[i].val+a[i].id*(LL)mid);
        sort(a+1,a+n+1);
        LL sum=0;
        for(int i=1; i<=mid; i++)
        {
            sum+=a[i].sum;
            if(sum>s)
                break;
        }
        if(sum<=s)
        {
            cnt=mid;
            ans=sum;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
