#include <bits/stdc++.h>
using namespace std;

int cnt[5];
char s[260];
char g[]={'A','G','C','T'};

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    if(n%4)
    {
        puts("===");
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        if(s[i]=='A')
            cnt[0]++;
        if(s[i]=='G')
            cnt[1]++;
        if(s[i]=='C')
            cnt[2]++;
        if(s[i]=='T')
            cnt[3]++;
    }
    for(int i=0; i<4; i++)
    {
        if(cnt[i]>n/4)
        {
            puts("===");
            return 0;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(s[i]=='?')
        {
            for(int j=0; j<4; j++)
            {
                if(cnt[j]<n/4)
                {
                    cnt[j]++;
                    s[i]=g[j];
                    break;
                }
            }
        }
    }
    printf("%s\n",s);
    return 0;
}
