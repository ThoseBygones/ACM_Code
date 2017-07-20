#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define LL long long
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007

//p,q互质，求(x+a)/(b+y)==p/q
//即求x+a==kp and y+b==kq;
//二分k
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        LL x,y,p,q;
        cin >> x >> y >> p >> q;
        LL l=0,r=INF;
        LL ans=-1;
        while(l<=r)
        {
            LL mid=(l+r)>>1;
            LL a=mid*p-x;
            LL b=mid*q-y;
            if(a>=0 && b>=0 && a<=b)
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(ans==-1)
            cout << "-1" << endl;
        else
            cout << ans*q-y << endl;
    }
    return 0;
}
