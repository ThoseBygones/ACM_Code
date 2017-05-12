#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[10005];
int cnt[5];

int main()
{
    while (gets(str))
    {
        int ans=0;
        int len=strlen(str);
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<len; i++)
        {
            if(str[i]=='h')
                cnt[0]++;
            if(str[i]=='a' && cnt[0] && cnt[0]>cnt[1])
                cnt[1]++;
            if(str[i]=='p' && cnt[1] && (cnt[1]*2>cnt[2]))
                cnt[2]++;
            if(str[i]=='y' && cnt[2]>=2 && cnt[1] && cnt[0])
            {
                ans++;
                cnt[0]--;
                cnt[1]--;
                cnt[2]-=2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
