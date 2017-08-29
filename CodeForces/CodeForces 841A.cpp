#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char s[MAXN];
int cnt[30];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(int i=0; i<n; i++)
        cnt[s[i]-'a']++;
    for(int i=0; i<26; i++)
    {
        if(cnt[i]>k)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
