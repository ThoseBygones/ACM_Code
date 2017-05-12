#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k[5];
    for(int i=0; i<4; i++)
    cin >> k[i];
    int cnt1=k[0];
    for(int i=2; i<4; i++)
        cnt1=min(cnt1,k[i]);
    k[0]-=cnt1;
    int cnt2=min(k[0],k[1]);
    int ans=256*cnt1+32*cnt2;
    cout << ans << endl;
    return 0;
}
