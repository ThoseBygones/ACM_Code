#include <iostream>
using namespace std;

int main()
{
    string str[2]={"I hate ","I love "};
    string mid="that ";
    string ter="it";
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << str[i%2];
        if(i!=n-1)
            cout << mid;
        else
            cout << ter << endl;
    }
    return 0;
}
