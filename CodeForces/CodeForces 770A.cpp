#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        putchar(i%k+'a');
    puts("");
    return 0;
}
