#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    int n;
    LL k;
    scanf("%d%I64d",&n,&k);
    int cnt=1;
    while(cnt<=n)
    {
        if(k%2)
            break;
        k>>=1;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
