#include <iostream>
#include <cmath>
#define MAXN 100005
using namespace std;

int n;
int l[MAXN],r[MAXN];

int main()
{
    cin >> n;
    int cntl=0,cntr=0;
    for(int i=1; i<=n; i++)
    {
        cin >> l[i] >> r[i];
        cntl+=l[i];
        cntr+=r[i];
    }
    int mmax=abs(cntl-cntr);
    int temp=0;
    for(int i=1; i<=n; i++)
    {
        int res=abs((cntl-l[i]+r[i])-(cntr-r[i]+l[i]));
        if(res>mmax)
        {
            mmax=res;
            temp=i;
        }
    }
    cout << temp << endl;
    return 0;
}
