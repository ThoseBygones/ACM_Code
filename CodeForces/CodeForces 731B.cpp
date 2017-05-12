#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];

int main()
{
    int n;
    cin >> n;
    bool flag=true;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=1; i<n; i++)
    {
        a[i-1]-=(a[i-1]/2)*2;
        int temp=min(a[i-1],a[i]);
        a[i]-=temp;
        a[i-1]-=temp;
        if(a[i-1]%2)
            flag=false;
    }
    //cout << flag << endl;
    if(a[n-1]%2)
        flag=false;
    //cout << flag << endl;
    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
