#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1000005

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int cnt=1;
    int left=MAXN;
    for(int i=n-1; i>0; i--)
    {
        if(i+1-a[i+1]<left)
            left=i+1-a[i+1];
        if(left>i)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
