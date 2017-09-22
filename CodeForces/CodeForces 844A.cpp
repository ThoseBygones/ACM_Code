#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int vis[30];
char s[MAXN];

int main()
{
    scanf("%s",s);
    int n;
    scanf("%d",&n);
    int len=strlen(s);
    int cnt=0;
    for(int i=0; i<len; i++)
    {
        if(!vis[s[i]-'a'])
        {
            vis[s[i]-'a']=1;
            cnt++;
        }
    }
    if(n>len)
        puts("impossible");
    else
        printf("%d\n",n-cnt>0?n-cnt:0);
    return 0;
}
