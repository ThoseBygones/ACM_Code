#include <iostream>
#include <cstring>
using namespace std;

char str[105];
char ans[105];

int main()
{
    int n;
    cin >> n;
    cin >> str;
    for(int i=0; i<n; i++)
    {
        int p=i+3;
        if(str[i]=='o' && str[i+1]=='g' && str[i+2]=='o')
        {
            ans[i]='*';
            ans[i+1]='*';
            ans[i+2]='*';
            while(str[p]=='g' && str[p+1]=='o')
            {
                ans[p]='0';
                ans[p+1]='0';
                p=p+2;
            }
            i=p-1;
        }
        else
            ans[i]=str[i];
    }
    for(int i=0; i<n; i++)
    {
        if(ans[i]!='0')
            cout << ans[i];
    }
    cout << endl;
    return 0;
}
