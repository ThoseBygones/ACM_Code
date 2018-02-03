#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define LL long long

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int p1=1,p2=2,s=3;
    bool flag=true;
    for(int i=0; i<n; i++)
    {
        if(a[i]==p1)
            swap(p2,s);
        else if(a[i]==p2)
            swap(p1,s);
        else
        {
            flag=false;
            break;
        }
    }
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
