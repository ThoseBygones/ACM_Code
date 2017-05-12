#include <iostream>
using namespace std;

int a[505];
int n,k,cnt;

int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n-1; i++)
    {
        while(a[i]+a[i+1]<k)
        {
            a[i+1]++;
            cnt++;
        }
    }
    cout << cnt << endl;
    cout << a[0];
    for(int i=1; i<n; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
