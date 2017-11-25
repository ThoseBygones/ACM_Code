#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

char s[MAXN];
char t[] = "CODEFORCES";

int main()
{
    scanf("%s",&s);
    int len=strlen(s);
    int p=0;
    int q1=0,q2=9;
    while(s[p]==t[q1])
    {
        p++;
        q1++;
    }
    q1--;
    p=len-1;
    while(s[p]==t[q2])
    {
        p--;
        q2--;
    }
    if(q1>=q2)
        puts("YES");
    else
        puts("NO");
    return 0;
}
