#include <iostream>
using namespace std;

int main()
{
    int n,a[5005];
    cin >> n;
    cout << "? 2 3" << endl;
    cin >> a[1];
    for(int i=2; i<=n; i++)
    {
        cout << "? 1 " << i << endl;
        cin >> a[i];
    }
    int sum=0;
    for(int i=1; i<=3; i++)
        sum+=a[i];
    sum/=2;
    a[1]=sum-a[1];
    for(int i=2; i<=n; i++)
        a[i]-=a[1];
    cout << "!";
    for(int i=1; i<=n; i++)
        cout << " " << a[i];
    cout << endl;
    return 0;
}
