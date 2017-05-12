#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char alice[12];
char bob[12];
int ans[12];
int res[12];

int main()
{
    memset(alice,0,sizeof(alice));
    memset(bob,0,sizeof(bob));
    memset(ans,0,sizeof(ans));
    memset(res,0,sizeof(res));
    while(cin >> alice)
    {
        cin >> bob;
        for(int i=0; i<strlen(alice); i++)
            res[i]=alice[i]-'0';
        for(int i=0; i<strlen(bob); i++)
            ans[i]=bob[i]-'0';
        sort(res,res+strlen(alice));
        if(res[0]==0)
        {
            for(int i=1; i<strlen(alice); i++)
            {
                if(res[i]!=0)
                {
                    swap(res[0],res[i]);
                    break;
                }
            }
        }
        bool flag=true;
        if(strlen(alice)!=strlen(bob))
            flag=false;
        for(int i=0; i<strlen(alice); i++)
        {
            if(ans[i]!=res[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout << "OK" << endl;
        else
            cout << "WRONG_ANSWER" << endl;
    }
    return 0;
}
