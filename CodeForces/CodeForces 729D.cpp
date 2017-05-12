#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n,a,b,k;
char grid[200005];

vector <int> shot;

int main()
{
    cin >> n >> a >> b >> k;
    cin >> grid+1;
    int p=1;
    int cnt=0;
    while(p<=n)
    {
        if(grid[p]=='0')
        {
            bool flag=true;
            for(int i=p; i<=p+b-1; i++)
            {
                if(grid[i]=='1')
                {
                    p=i;
                    flag=false;
                    break;
                }
            }
            if(flag && p+b-1<=n)
            {
                p+=b-1;
                grid[p]='1';
                shot.push_back(p);
                cnt++;
            }
        }
        p++;
    }
    int ans=cnt-a+1;
    cout << ans << endl;
    for(int i=0; i<ans; i++)
        cout << shot[i] << " ";
    cout << endl;
    return 0;
}
