#include<iostream>
using namespace std;

int main()
{
    int t,n,m,a;
    cin >> t;
    while(t--)
    {
        int cnt=0;
        cin >> n >> m;
        for(int i=0; i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> a;
                if(a==1)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
