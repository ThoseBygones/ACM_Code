#include <iostream>
using namespace std;

int num[100];

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i=1; i<=n; i++)
            cin >> num[i];
        if(n==1)
        {
            if(num[1]==0)
                cout << "UP" << endl;
            else if(num[1]==15)
                cout << "DOWN" << endl;
            else
                cout << "-1" << endl;
            continue;
        }
        else
        {
            if(num[n]==0)
                cout << "UP" << endl;
            else if(num[n]==15)
                cout << "DOWN" << endl;
            else if(num[n]>num[n-1])
                cout << "UP" << endl;
            else if(num[n]<num[n-1])
                cout << "DOWN" << endl;
            continue;
        }
    }
    return 0;
}
