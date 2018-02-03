#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

char s[MAXN];
int vis[30];
int app[30];

int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    int ans=0;
    char op[2];
    bool flag=false;
    n--;
    while(n--)
    {
        scanf("%s",op);
        scanf("%s",s);
        int len=strlen(s);
        if(op[0]=='.')  //该串内字符均不是正确答案
        {
            for(int i=0; i<len; i++)
                vis[s[i]-'a']=1;
        }
        else if(op[0]=='?') //该询问是否值得？
        {
            if(flag)
                ans++;
            else
                vis[s[0]-'a']=1;
        }
        else if(op[0]=='!') //该串内有字符为正确答案
        {
            if(flag)
                ans++;
            else
            {
                memset(app,0,sizeof(app));
                for(int i=0; i<len; i++)
                    app[s[i]-'a']=1;
                for(int i=0; i<26; i++)
                {
                    if(!app[i])
                        vis[i]=1;
                }
            }
        }
        if(!flag)
        {
            cnt=0;
            for(int i=0; i<26; i++) //枚举是否已经可以确定答案字符
            {
                if(!vis[i])
                    cnt++;
            }
            if(cnt==1)
                flag=true;
        }
    }
    scanf("%s",op);
    scanf("%s",s);
    printf("%d\n",ans);
    return 0;
}
