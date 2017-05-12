#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int m=min(a,b);
    if(m%2)
        cout << "Akshat" << endl;
    else
        cout << "Malvika" << endl;
    return 0;
}
