#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char str[260];

int main()
{
    int n;
    while(cin >> n)
    {
        cin >> str;
        int maxletter=0;
        int cntword=0;
        int cntletter=0;
        bool parentheses=false;
        for(int i=0; i<n; i++)
        {
            if(str[i]=='(')
            {
                parentheses=true;
                maxletter=max(maxletter,cntletter);
                cntletter=0;
                continue;
            }
            if(str[i]==')')
            {
                parentheses=false;
                if(str[i]==')' && str[i-1]!='_' && str[i-1]!='(')
                    cntword++;
                continue;
            }
            if(!parentheses)
            {
                if(str[i]=='_')
                {
                    maxletter=max(maxletter,cntletter);
                    cntletter=0;
                }
                else
                    cntletter++;
            }
            else
            {
                if(str[i]=='_' && str[i-1]!='(' && str[i-1]!='_')
                    cntword++;
            }
        }
        if(str[n-1]!=')' || str[n-1]!='_')
            maxletter=max(maxletter,cntletter);
        cout << maxletter << " " << cntword << endl;
    }
    return 0;
}
