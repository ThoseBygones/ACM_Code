#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

char s[MAXN];
char Min[MAXN];
stack <char> sta;

int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=n-1; i>=0; i--)
    {
        if(i==n-1)
            Min[i]=s[i];
        else
            Min[i]=min(s[i],Min[i+1]);
    }
    for(int i=0; i<n; i++)
    {
        if(sta.empty())
            sta.push(s[i]);
        else
        {
            while(!sta.empty())
            {
                int t=sta.top();
                if(t<=Min[i])
                {
                    printf("%c",sta.top());
                    sta.pop();
                }
                else
                    break;
            }
            sta.push(s[i]);
        }
    }
    while(!sta.empty())
    {
        printf("%c",sta.top());
        sta.pop();
    }
    puts("");
    return 0;
}
