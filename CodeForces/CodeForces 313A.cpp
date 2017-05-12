#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int n1=n/10;
    int n2=n/100*10+n%10;
    cout << max(n,max(n1,n2)) << endl;
    return 0;
}
