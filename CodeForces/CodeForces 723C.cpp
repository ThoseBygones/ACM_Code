#include <iostream>
using namespace std;

int n,m,a[2005],cnt[2005];

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(a[i]<=m)
            cnt[a[i]]++;
    }
    int ans=n/m;
    int change=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; cnt[i]<ans; j++)
        {
            if(a[j]>m)
            {
                cnt[i]++;
                a[j]=i;
                change++;
            }
            else if(cnt[a[j]]>ans)
            {
                cnt[a[j]]--;
                cnt[i]++;
                a[j]=i;
                change++;
            }
        }
    }
    cout << ans << " " << change << endl;
    for(int i=1; i<n; i++)
        cout << a[i] << " ";
    cout << a[n] << endl;
    return 0;
}
