#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

map <char,char> mp;

char l1[30],l2[30];
char s[MAXN];
char ans[MAXN];
//-32
int main()
{
    scanf("%s",l1);
    scanf("%s",l2);
    scanf("%s",s);
    for(int i=0; i<26; i++)
    {
        mp[l1[i]]=l2[i];
        mp[l1[i]-32]=l2[i]-32;
    }
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
            ans[i]=mp[s[i]];
        else
            ans[i]=s[i];
    }
    printf("%s\n",ans);
    return 0;
}
