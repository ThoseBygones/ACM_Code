#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 105

char a[5];
char str[10];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    int cnt1=0; //出发次数
    int cnt2=0; //回来次数
    bool flag1,flag2;
    for(int i=1; i<=n; i++)
    {
        scanf("%s",str);
        flag1=true,flag2=true;
        for(int j=0; j<3; j++)
        {
            if(str[j]!=a[j])
            {
                flag1=false;
                break;
            }
        }
        for(int j=0; j<3; j++)
        {
            if(str[j+5]!=a[j])
            {
                flag2=false;
                break;
            }
        }
        if(flag1)
            cnt1++;
        if(flag2)
            cnt2++;
    }
    if(cnt1==cnt2)
        puts("home\n");
    else
        puts("contest\n");
    return 0;
}
