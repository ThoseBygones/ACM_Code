#include <bits/stdc++.h>
using namespace std;

#define MAXN 205

char s[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    gets(s);
    int cnt=0;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]==' ')
        {
            ans=max(ans,cnt);
            cnt=0;
        }
        else if(s[i]>='A' && s[i]<='Z')
            cnt++;
    }
    ans=max(ans,cnt);
    printf("%d\n",ans);
    return 0;
}
