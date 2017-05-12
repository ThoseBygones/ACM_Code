#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[100000],b[100000];

int main()
{
    int len1,len2,i;
    while(scanf("%s %s",a,b)!=EOF)
    {
        len1=strlen(a);
        len2=strlen(b);
        if(strchr(a,'.'))
        {
            while(a[--len1]=='0');
            if(a[len1]=='.')
                len1--;
            a[len1+1]='\0';
        }
        if(strchr(b,'.'))
        {
            while(b[--len2]=='0');
            if(b[len2]=='.')
                len2--;
            b[len2+1]='\0';
        }
        if(strcmp(a,b)==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
