#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[100005],t[100005];
    while(~scanf("%s %s",s,t))
    {
        int len1,len2;
        len1=strlen(s);
        len2=strlen(t);
        int i=0;
        int j=0;
        while(1)
        {
            if(i==len1)
            {
                printf("Yes\n");
                break;
            }
            if(i<len1 && j==len2)
            {
                printf("No\n");
                break;
            }
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
    }
    return 0;
}
