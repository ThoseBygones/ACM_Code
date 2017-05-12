#include <iostream>
#include <map>
using namespace std;

map <int,int> mp;
int n,a,b;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        mp.clear();
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a >> b;
            mp[a]+=b;
        }
        int ans=0;
        int grid=0;
        for(int i=0; i<=1000; i++)
        {
            if(mp[i])
            {
                grid+=mp[i]/64;
                if(mp[i]%64)
                    grid++;
            }
        }
        ans+=grid/36;
        if(grid%36)
            ans++;
        cout << ans << endl;
    }
    return 0;
}
