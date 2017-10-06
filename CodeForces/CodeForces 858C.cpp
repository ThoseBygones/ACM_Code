#include <bits/stdc++.h>
using namespace std;

#define MAXN 3005

char s[MAXN];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int cnt=0;
    for(int i=0; i<len; i++)
    {
        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
        {
            cnt++;
            if(cnt==3)
            {
                if(s[i]==s[i-1] && s[i-1]==s[i-2])
                    cnt--;
                else
                {
                    printf(" ");
                    cnt=1;
                }
            }
        }
        else
            cnt=0;
        printf("%c",s[i]);
    }
    puts("");
    return 0;
}
