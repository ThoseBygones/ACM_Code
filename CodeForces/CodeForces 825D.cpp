#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define INF 0x3f3f3f3f

char s[MAXN];
char t[MAXN];
int have[30];
int need[30];

int main()
{
    scanf("%s",s);
    scanf("%s",t);
    int lens=strlen(s);
    int lent=strlen(t);
    int cnt=0;  //'?'的数量
    for(int i=0; i<lens; i++)
    {
        if(s[i]!='?')
            have[s[i]-'a']++;
    }
    for(int i=0; i<lent; i++)
        need[t[i]-'a']++;
    int tmp=INF;  //最多能组成多少个子串
    for(int i=0; i<26; i++)
    {
        if(need[i])
            tmp=min(tmp,have[i]/need[i]);
    }
    for(int i=0; i<26; i++)
    {
        if(need[i])
            have[i]-=(need[i]*tmp);
    }

    int p=0;
    for(int i=0; i<lens; i++)
    {
        if(s[i]=='?')
        {
            bool flag=false;
            while(!flag)
            {
                if(!need[p])
                    p++;
                else
                {
                    if(have[p]<need[p])
                    {
                        have[p]++;
                        flag=true;
                        s[i]='a'+p;
                    }
                    if(have[p]>=need[p])
                    {
                        have[p]-=need[p];
                        p++;
                    }
                }
                if(p>=26)
                    p=0;
            }
        }
    }
    printf("%s\n",s);
    return 0;
}
