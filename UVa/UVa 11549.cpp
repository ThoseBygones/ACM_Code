#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#define LL long long
using namespace std;

map <LL,LL> cal;

int main()
{
    int t;
    LL n,k,mmax;
    cin >> t;
    while(t--)
    {
        cal.clear();
        cin >> n >> k;
        mmax=k;
        while(!cal.count(k))
        {
            cal[k]++;
            k*=k;
            LL temp=pow(10,n);
            while(k>=temp)
                k/=10;
            mmax=max(mmax,k);
        }
        cout << mmax << endl;
    }
    return 0;
}
