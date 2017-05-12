#include <iostream>
#include <cstring>
using namespace std;

char num[100005];

int main()
{
    cin >> num;
    int len=strlen(num);
    bool flag=true;
    for(int i=0; i<len-1; i++)
    {
        if(num[i]=='0' && flag)
        {
            flag=false;
            continue;
        }
        cout << num[i];
    }
    if(!flag)
        cout << num[len-1];
    cout << endl;
    return 0;
}
