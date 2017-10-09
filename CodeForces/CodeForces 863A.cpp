#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char s[15];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int p=0,q=len-1;
    while(s[q]=='0')
        q--;
    bool flag=true;
    while(p<q)
    {
        if(s[p]!=s[q])
        {
            flag=false;
            break;
        }
        p++;
        q--;
    }
    puts(flag?"YES":"NO");
    return 0;
}
