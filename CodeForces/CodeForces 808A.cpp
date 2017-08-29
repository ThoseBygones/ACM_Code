#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int cnt[10];

int main()
{
    int n;
    scanf("%d",&n);
    int temp=n;
    int cnt=0;
    while(temp)
    {
        temp/=10;
        cnt++;
    }
    int ans=1;
    for(int i=0; i<cnt-1; i++)
        ans*=10;
    printf("%d\n",ans-n%ans);
    return 0;
}
