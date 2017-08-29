#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int oddcnt=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]&1)
            oddcnt++;
    }
    if(oddcnt)
        puts("First");
    else
        puts("Second");
    return 0;
}
