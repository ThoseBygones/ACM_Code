#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];
        int m=a[0];
        int ans=a[0]-a[1];
        for(int i=1; i<n; i++)
        {
            ans=max(ans,m-a[i]);
            m=max(m,a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
