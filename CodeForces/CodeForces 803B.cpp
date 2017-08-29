#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int a[MAXN];
vector <int> z;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(!a[i])
            z.push_back(i);
    }
    for(int i=0; i<=z[0]; i++)
        printf("%d ",z[0]-i);
    int p=1;
    int sz=z.size();
    for(int i=z[0]+1; i<=z[sz-1]; i++)
    {
        if(i>z[p])
            p++;
        printf("%d ",min(i-z[p-1],z[p]-i));
    }
    for(int i=z[sz-1]+1; i<n; i++)
        printf("%d ",i-z[sz-1]);
    puts("");
    return 0;
}
