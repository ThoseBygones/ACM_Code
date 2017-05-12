#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int a[MAXN],b[MAXN];
int num[MAXN];  //a序列每个元素相对b序列中每个元素的编号

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&b[i]);
    for(int i=1; i<=n; i++)
        num[b[i]]=i;    //相对顺序
    int ans=0;
    for(int i=1; i<n; i++)
    {
        if(num[a[i]]>num[a[i+1]])
        {
            //cout << i << endl;
            ans=n-i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
