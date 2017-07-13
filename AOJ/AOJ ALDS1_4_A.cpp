#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005

bool linear_search(int a[],int n,int key)
{
    int p=n;
    a[0]=key;
    while(a[p]!=key)
        p--;
    return p==0?false:true;
}

int main()
{
    int a[MAXN];
    int n,q,val;
    int cnt=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&val);
        if(linear_search(a,n,val))
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
