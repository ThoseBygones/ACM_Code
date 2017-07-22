#include <bits/stdc++.h>
using namespace std;

#define MAXN 1505

char s[MAXN];
int n,k;

int work(char ch)
{
    int ans=0;
    int l=0,r=0;
    int cnt=0;
    while(l<=r && r<n)
    {
        while(r<n && (s[r]==ch || cnt<k))
        {
            if(s[r]!=ch)
                cnt++;
            r++;
        }
        ans=max(ans,r-l);
        while(s[l]==ch && l<=r)
            l++;
        l++;
        cnt--;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        char col[2];
        scanf("%d%s",&k,col);
        int ans=work(col[0]);
        printf("%d\n",ans);
    }
    return 0;
}
