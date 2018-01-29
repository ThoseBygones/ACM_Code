#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 25
#define MP make_pair

typedef pair<int,int> PII;
PII ans[MAXN];
int a[MAXN],b[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        ans[i]=MP(a[i],i);
    }
    sort(ans,ans+n);
    for(int i=0; i<n; i++)
        b[ans[(i+1)%n].second]=ans[i].first;
    for(int i=0; i<n; i++)
    {
        if(i)
            printf(" %d",b[i]);
        else
            printf("%d",b[i]);
    }
    puts("");
    return 0;
}
