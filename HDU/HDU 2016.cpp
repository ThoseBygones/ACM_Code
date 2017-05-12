#include <iostream>
#include <algorithm>
using namespace std;

int a[105];

int main()
{
    int n;
    while(cin >> n,n)
    {
        for(int i=0; i<n; i++)
            cin >> a[i];
        int mmin=a[0];
        int temp=0;
        for(int i=1; i<n; i++)
        {
            if(mmin>a[i])
            {
                temp=i;
                mmin=a[i];
            }
        }
        swap(a[temp],a[0]);
        for(int i=0; i<n-1; i++)
            cout << a[i] << " ";
        cout << a[n-1] << endl;
    }
    return 0;
}
