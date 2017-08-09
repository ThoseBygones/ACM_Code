#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int a[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    int cnt=0;
    for(int i=1; i<=t; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<=35)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
