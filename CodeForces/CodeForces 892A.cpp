#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define LL long long

int a[MAXN];
int b[MAXN];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    int n;
    scanf("%d",&n);
    LL sum=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(int i=0; i<n; i++)
        scanf("%d",&b[i]);
    sort(b,b+n,cmp);
    if((LL)(b[0]+b[1])>=sum)
        puts("YES");
    else
        puts("NO");
    return 0;
}
