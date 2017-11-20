#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1005

char s[105];
int cnt[30];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0; i<len; i++)
        cnt[s[i]-'a']++;
    sort(cnt,cnt+26);
    int ans=0;
    for(int i=0; i<=23; i++)
    {
        if(cnt[i])
            ans+=cnt[i];
    }
    printf("%d\n",ans);
    return 0;
}
