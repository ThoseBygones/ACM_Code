#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 105

char a[505];

int main()
{
    scanf("%s",a);
    int len=strlen(a);
    int n=max(len,26);
    bool flag=true;
    if(a[0]!='a')
        flag=false;
    char big='a';
    for(int i=1; i<n; i++)
    {
        if(a[i]>a[i-1])
        {
            if(a[i]==big+1)
                big=a[i];
            else if(a[i]>big+1)
            {
                flag=false;
                break;
            }
        }
    }
    if(flag)
        puts("YES\n");
    else
        puts("NO\n");
}
