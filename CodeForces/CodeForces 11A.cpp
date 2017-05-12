#include <iostream>
using namespace std;

int a[2005];

int main()
{
    int n,d;
    while(cin >> n >> d)
    {
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        int cnt=0;
        for(int i=1; i<n; i++)
        {
            if(a[i-1] >= a[i])
            {
                int temp=a[i-1]-a[i]+1;
                int num;
                if(temp%d)
                    num=temp/d+1;
                else
                    num=temp/d;
                //cout << num << endl;
                a[i]+=num*d;
                cnt+=num;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
