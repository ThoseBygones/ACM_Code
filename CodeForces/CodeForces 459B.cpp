#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

LL num[200005];

int main()
{
    LL n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> num[i];
    sort(num,num+n);
    LL cnt1=0,cnt2=0;
    for(int i=0; i<n; i++)
    {
        if(num[i]==num[0])
            cnt1++;
        else
            break;
    }
    for(int i=n-1; i>=0; i--)
    {
        if(num[i]==num[n-1])
            cnt2++;
        else
            break;
    }
    if(cnt1==n)
        cout << "0 " << (n-1)*n/2 << endl;
    else
        cout << num[n-1]-num[0] << " " << cnt1*cnt2 << endl;
    return 0;
}
