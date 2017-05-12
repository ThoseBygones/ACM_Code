#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

int main()
{
    int n;
    scanf("%d",&n);
    int low=sqrt(n);
    while(n%low)
        low--;
    printf("%d %d\n",low,n/low);
    return 0;
}
