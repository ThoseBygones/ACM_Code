#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=1; i<n-1; i++)
    {
        if(a[i-1]<a[i] && a[i]>a[i+1])
            cnt++;
        if(a[i-1]>a[i] && a[i]<a[i+1])
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
