#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005

char s[MAXN];
char t[MAXN];
char ans[MAXN];

bool cmp(char x,char y)
{
    return x>y;
}

int main()
{
    scanf("%s",s+1);
    scanf("%s",t+1);
    int len=strlen(s+1);
    sort(s+1,s+len+1);
    sort(t+1,t+len+1,cmp);
    int p1=1,q1=len/2;
    int p2=1,q2=len/2;
    if(len&1)
        q1++;
    int l=1,r=len;
    int cnt=1;
    while(l<=r)
    {
        if(cnt&1)
        {
            if(s[p1]<t[p2])
                ans[l++]=s[p1++];
            else
                ans[r--]=s[q1--];
        }
        else
        {
            if(s[p1]<t[p2])
                ans[l++]=t[p2++];
            else
                ans[r--]=t[q2--];
        }
        cnt++;
    }
    printf("%s\n",ans+1);
    return 0;
}
