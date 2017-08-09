#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

char s[MAXN];
int vis[11];

int main()
{
    int k;
    scanf("%d",&k);
    scanf("%s",s);
    int len=strlen(s);
    int sum=0;
    for(int i=0; i<len; i++)
    {
        sum+=s[i]-'0';
        if(sum>=k)
        {
            puts("0");
            return 0;
        }
        vis[s[i]-'0']++;
    }
    int cnt=0;
    for(int i=0; i<9; i++)
    {
        while(vis[i])
        {
            vis[i]--;
            vis[9]++;
            sum+=9-i;
            cnt++;
            if(sum>=k)
            {
                printf("%d\n",cnt);
                return 0;
            }
        }
    }
    return 0;
}
