#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char s[MAXN];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int p=0;
    int q=len-1;
    int cnt=0;
    while(p<=q)
    {
        if(s[p]!=s[q])
        {
            cnt++;
        }
        p++;
        q--;
    }
    if(cnt==1 || (cnt==0 && len&1))
        puts("YES");
    else
        puts("NO");
    return 0;
}
