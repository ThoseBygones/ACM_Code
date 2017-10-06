#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int a=n;
    int cnt=0;
    for(int i=2; i*i<=a; i++)
    {
        if(a%i==0)
        {
            cnt++;
            a/=i;
        }
        if(a%i==0)
        {
            puts("NO");
            return 0;
        }
    }
    if(a>1)
        cnt++;
    if(cnt!=3)
        puts("NO");
    else
        puts("YES");
    return 0;
}
