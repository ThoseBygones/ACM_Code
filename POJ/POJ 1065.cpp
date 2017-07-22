#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005

struct Stick
{
    int len;
    int wid;
    bool operator <(const Stick &a) const
    {
        if(len==a.len)
            return wid<a.wid;
        return len<a.len;
    }
} s[MAXN];

int vis[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
            scanf("%d%d",&s[i].len,&s[i].wid);
        sort(s,s+n);
        int ans=0;
        while(true)
        {
            int cnt=0;
            int maxLen=0,maxWid=0;
            for(int i=0; i<n; i++)
            {
                if(!vis[i] && maxLen<=s[i].len && maxWid<=s[i].wid)
                {
                    cnt++;
                    vis[i]=1;
                    maxLen=s[i].len;
                    maxWid=s[i].wid;
                }
            }
            if(!cnt)
                break;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
