#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n/2; i+=2)
        swap(a[i],a[n-i+1]);
    for(int i=1; i<=n; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
