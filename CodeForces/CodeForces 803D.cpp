#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

char s[MAXN];
int k;
int len;

bool check(int val)
{
    int cnt=0;
    for(int i=0; i<len; )
    {
        cnt++;
        int j=i+val;
        if(j>=len)
            break;
        while(s[j-1]!=' ' && s[j-1]!='-' && j>i)
            j--;
        if(j==i)
            return false;
        i=j;
    }
    if(cnt<=k)
        return true;
    return false;
}

int main()
{
    scanf("%d",&k);
    getchar();
    gets(s);
    len=strlen(s);
    int l=0;
    int r=len;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
