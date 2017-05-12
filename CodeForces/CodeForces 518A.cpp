#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 105

char s[MAXN],t[MAXN],ans[MAXN];

int main()
{
    while(cin >> s >> t)
    {
        int len=strlen(s);
        for(int i=0; i<len; i++)
            ans[i]=s[i];
        for(int i=len-1; i>=0; i--)
        {
            if(ans[i]=='z')
            {
                ans[i]='a';
                continue;
            }
            else
                ans[i]++;
            break;
        }
        if(strcmp(t,ans)<=0)
            cout << "No such string" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
