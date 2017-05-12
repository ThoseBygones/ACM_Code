#include <iostream>
using namespace std;

char str[100005];

int main()
{
    int n;
    cin >> n;
    cin >> str;
    int cnta=0,cntd=0;
    for(int i=0; i<n; i++)
    {
        if(str[i]=='A')
            cnta++;
        else if(str[i]=='D')
            cntd++;
    }
    if(cnta>cntd)
        cout << "Anton" << endl;
    else if(cnta==cntd)
        cout << "Friendship" << endl;
    else
        cout << "Danik" << endl;
    return 0;
}
