#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

char s[MAXN];
int pre[30];
int dis[MAXN];

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    memset(pre,-1,sizeof(pre));

    for(int i=0; i<len; i++)
    {
        int x=s[i]-'a';
        dis[x]=max(dis[x],i-pre[x]);
        pre[x]=i;
    }
    for(int i=0; i<26; i++)
        dis[i]=max(dis[i],len-pre[i]);
    int ans=len;
    for(int i=0; i<26; i++)
        ans=min(ans,dis[i]);
    printf("%d\n",ans);
    return 0;
}
