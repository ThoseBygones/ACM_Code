#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 300005

LL a[MAXN];    //USBÊó±ê
LL b[MAXN];    //PS/2Êó±ê

int main()
{
    LL x,y,z,m;
    cin >> x >> y >> z;
    cin >> m;
    string s;
    LL p;
    LL cnta=0,cntb=0;
    while(m--)
    {
        cin >> p >> s;
        if(s=="USB")
            a[++cnta]=p;
        else if(s=="PS/2")
            b[++cntb]=p;
    }
    //cout << x << " " << y << " " << z << endl;
    sort(a+1,a+cnta+1);
    sort(b+1,b+cntb+1);
    LL t1=1,t2=1;
    LL ans=0;
    while(t1<=cnta && x>0)
    {
        ans+=a[t1];
        t1++;
        x--;
    }
    while(t2<=cntb && y>0)
    {
        ans+=b[t2];
        t2++;
        y--;
    }
    while((t1<=cnta || t2<=cntb) && z>0)
    {
        LL Min=1e18;
        if(t1<=cnta)
            Min=min(Min,a[t1]);
        if(t2<=cntb)
            Min=min(Min,b[t2]);
        //cout << Min << endl;
        if(Min!=1e18)
        {
            ans+=Min;
            z--;
            if(Min==a[t1])
                t1++;
            else
                t2++;
        }
    }
    cout << t1+t2-2 << " " << ans << endl;
    return 0;
}
