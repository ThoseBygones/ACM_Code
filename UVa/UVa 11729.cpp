#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct commando
{
    int atime;
    int etime;
} t[1005];

int cmp(commando a,commando b)
{
    return a.etime > b.etime;
}

int main()
{
    int n;
    int cnt=1;
    while(cin >> n,n)
    {
        for(int i=0; i<n; i++)
            cin >> t[i].atime >> t[i].etime;
        sort(t,t+n,cmp);
        int ans=0;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=t[i].atime;
            ans=max(ans,sum+t[i].etime);
        }
        cout << "Case " << cnt++ << ": " << ans << endl;
    }
    return 0;
}
