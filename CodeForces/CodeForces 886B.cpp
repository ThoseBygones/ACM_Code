#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

set <int> s;

int a[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    for(int i=n-1; i>=0; i--)
    {
        if(s.size()==1)
            break;
        if(s.find(a[i])!=s.end())
            s.erase(a[i]);
    }
    printf("%d\n",*s.begin());
    return 0;
}
