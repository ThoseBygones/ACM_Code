#include <iostream>
#include <cstring>
#define LL long long
using namespace std;

LL pos[100005]; //记录数列中各数字在数列中的位置

int main()
{
    LL n,m;
    while(cin >> n)
    {
        memset(pos,0,sizeof(pos));
        LL a=0,b=0;
        for(int i=1; i<=n; i++)
        {
            LL temp;
            cin >> temp;
            pos[temp]=i;
        }
        cin >> m;
        for(int i=1; i<=m; i++)
        {
            LL temp;
            cin >> temp;
            if(pos[temp])
            {
                a+=pos[temp];
                b+=n-pos[temp]+1;
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
