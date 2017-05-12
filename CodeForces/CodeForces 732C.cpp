#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

LL a[5],m,ans;

int main()
{
    for(int i=0; i<3; i++)
    {
        cin >> a[i];
        m=max(a[i],m);
    }
    m--;
    for(int i=0; i<3; i++)
        ans+=max(m-a[i],0LL);
    cout << ans << endl;
    return 0;
}
