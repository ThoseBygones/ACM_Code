#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[105];

int main()
{
    int n,limak;
    cin >> n;
    cin >> limak;
    for(int i=0; i<n-1; i++)
        cin >> a[i];
    int ans=0;
    while(limak <=(*max_element(a,a+n-1)))
    {
        sort(a,a+n-1);
        a[n-2]--;
        limak++;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
