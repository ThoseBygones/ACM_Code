#include <iostream>
using namespace std;

int cut(int x)
{
    if(x==1)
        return 1;
    return cut(x/2)+1;
}

int main()
{
    int n;
    while(cin >> n)
        cout << cut(n) << endl;
    return 0;
}
