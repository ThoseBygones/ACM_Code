#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

struct Node
{
    int val;
    int id;
    int a;
} b[MAXN];

int a[MAXN];
int ans[MAXN];

bool cmp1(int x,int y)
{
    return x>y;
}

bool cmp2(Node x,Node y)
{
    return x.val<y.val;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&b[i].val);
        b[i].id=i;
    }
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+n,cmp2);
    for(int i=1; i<=n; i++)
        ans[b[i].id]=a[i];
    for(int i=1; i<n; i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}
