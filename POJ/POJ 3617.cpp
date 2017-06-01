#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 2005

char s[MAXN];
char t[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        char temp[2];
        scanf("%s",temp);
        s[i]=temp[0];
    }
    //printf("%s\n",s);
    int p=0,q=n-1;
    int cnt=0;
    while(p<=q)
    {
        if(s[p]==s[q])
        {
            int i=p+1;
            int j=q-1;
            while(i<=j && s[i]==s[j])
            {
                i++;
                j--;
            }
            if(s[i]<s[j])
            {
                t[cnt++]=s[p];
                p++;
            }
            else
            {
                t[cnt++]=s[q];
                q--;
            }
        }
        else if(s[p]<s[q])
        {
            t[cnt++]=s[p];
            p++;
        }
        else
        {
            t[cnt++]=s[q];
            q--;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(i==n-1 || (i+1)%80==0)   //每行显示不超过80个字符
            printf("%c\n",t[i]);
        else
            printf("%c",t[i]);
    }
    return 0;
}
