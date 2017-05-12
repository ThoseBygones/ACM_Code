#include <iostream>
using namespace std;

int main()
{
    int a,b,c,ans[30],cnt=0;
    cin >> a >> b;
    c=b;
    for(cnt=0; b!=a; )
    {
        if(b && b%2==0)
            b>>=1;
        else if(b%10==1)
            b/=10;
        else
        {
            cout << "NO" << endl;
            return 0;
        }
        ans[++cnt]=b;
    }
    cout << "YES" << endl;
    cout << cnt+1 << endl;
    while(cnt)
        cout << ans[cnt--] << " ";
    cout << c << endl;
    return 0;
}
