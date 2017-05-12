#include <bits/stdc++.h>
#define LL long long
using namespace std;

int a[10];

int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",a+i);
        sum+=a[i];
    }
    printf("%d\n",sum/n);
    return 0;
}
