#include <iostream>
using namespace std;

char flag[105][105];

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        bool ok=true;
        for(int i=0; i<n; i++)
            cin >> flag[i];
        for(int i=1; i<n; i++)
        {
            if(flag[i-1][0]==flag[i][0])
            {
                ok=false;
                break;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(flag[i][j-1]!=flag[i][j])
                {
                    ok=false;
                    break;
                }
            }
            if(!ok)
                break;
        }
        if(ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
