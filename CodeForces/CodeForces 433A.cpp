#include <iostream>
using namespace std;

int n,temp,a[2];

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> temp;
        if(temp==200)
            a[1]++;
        else
            a[0]++;
    }
    if(a[0]%2 || (!a[0] && a[1]%2))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
