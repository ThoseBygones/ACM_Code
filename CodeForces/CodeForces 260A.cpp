#include <iostream>
#define LL long long
using namespace std;

int main()
{
    LL a,b,n;
    LL ans;
    cin >> a >> b >> n;
    bool flag=false;
    for(int i=0; i<=9; i++)
    {
        ans=a*10+i;
        if(ans%b==0)
        {
            flag=true;
            cout << ans;
            for(int j=1; j<n; j++)
                cout << "0";
            cout << endl;
            return 0;
        }
    }
    if(!flag)
        cout << "-1" << endl;
    return 0;
}
