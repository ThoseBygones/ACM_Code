#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char s[MAXN];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int cnt=0;
    bool flag=false;
    for(int i=len-1; i>=0; i--)
    {
        if(s[i]=='0')
            cnt++;
        else
        {
            if(cnt>=6)
            {
                flag=true;
                break;
            }
        }
    }
    puts(flag?"yes":"no");
    return 0;
}
