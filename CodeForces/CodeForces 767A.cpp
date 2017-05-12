#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005

int a[MAXN];
int cnt[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int Max=n;
    for(int i=1; i<=n; i++)
    {
        cnt[a[i]]=1;
        while(cnt[Max])
        {
            printf("%d ",Max);
            Max--;
        }
        printf("\n");
    }
    return 0;
}
