#include <iostream>
#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;

int n;
LL a[20];
LL sum,ans;

int main()
{
    int kase=1;
    while(cin >> n)
    {
        for(int i=0; i<n; i++)
            cin >> a[i];
        ans=0;
        for(int i=0; i<n; i++)
        {
            sum=1;
            for(int j=i; j<n; j++)
            {
                sum*=a[j];
                ans=max(ans,sum);
            }
        }
        cout << "Case #" << kase++ << ": The maximum product is " << ans << "." << endl << endl;
    }
    return 0;
}
