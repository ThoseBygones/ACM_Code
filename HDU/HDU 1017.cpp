#include<iostream>
using namespace std;
int main()
{
    int n,m,cnt,N;
    cin >> N;
    while(N--)
    {
        int kase=1;
        while(cin >> n >> m,n||m)
        {
            cnt=0;
            for(int i=1; i<=n-1; i++)
            {
                for(int j=i+1; j<=n-1; j++)
                {
                    if((i*i+j*j+m)%(i*j)==0)
                        cnt++;
                }
            }
            cout << "Case " << kase++ << ": " << cnt << endl;
        }
        if(N)
            cout << endl;
    }
    return 0;
}
