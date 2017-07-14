#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define MAXN 2005
#define LL long long

int a[MAXN],b[MAXN];

int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&a[i]);
        a[i]+=a[i-1];   //前缀和
    }
    for(int i=1; i<=n; i++)
        scanf("%d",&b[i]);
    sort(a+1,a+k+1);
    sort(b+1,b+n+1);
    set <int> s;
    for(int i=1; i<=k; i++)
    {
        int x=b[1]-a[i];    //设b[1]为第一个中间值，以此基准求出基础值x
        int p=2;
        for(int j=i+1; j<=k; j++)
        {
            if(b[p]-a[j]==x)
                p++;
        }
        if(p==n+1)  //全部中间值都能找到符合要求的位置
            s.insert(x);
    }
    printf("%d\n",s.size());
    return 0;
}
