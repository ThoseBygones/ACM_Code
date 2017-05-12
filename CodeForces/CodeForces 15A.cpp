#include <iostream>
#include <algorithm>
using namespace std;

struct house
{
    int center;
    int length;
} h[1005];

bool cmp(house a,house b)
{
    return a.center<b.center;
}

int main()
{
    int n,t;
    while(cin >> n >> t)
    {
        t*=2;
        int p,l;
        for(int i=0; i<n; i++)
        {
            cin >> p >> l;
            h[i].center=p*2;
            h[i].length=l*2;
        }
        sort(h,h+n,cmp);
        int cnt=0;
        for(int i=1; i<n; i++)
        {
            int dis=(h[i].center-h[i].length/2)-(h[i-1].center+h[i-1].length/2);
            if(dis>t)
                cnt+=2;
            else if(dis==t)
                cnt++;
        }
        cnt+=2;
        cout << cnt << endl;
    }
    return 0;
}
