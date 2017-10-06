#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define LL long long

int a[15];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    LL ans=1;
    a[1]=8;
    for(int i=2; i<=9; i++)
        a[i]=9;
    for(int i=1; i<=min(n,9); i++)
        ans*=a[i];
    cout << ans;
    for(int i=10; i<=n; i++)
        printf("0");
    puts("");
    return 0;
}
