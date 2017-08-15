#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005

int a[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt2=n*2;
    int cnt4=n;
    for(int i=1; i<=k; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=k; i++)
    {
        int temp=min(cnt4,a[i]/4);
        cnt4-=temp;
        a[i]-=temp*4;
    }
    cnt2+=cnt4; //cnt4空余下来的也可以放两个的（浪费两个）
    for(int i=1; i<=k; i++)
    {
        int temp=min(cnt2,a[i]/2);
        cnt2-=temp;
        a[i]-=temp*2;
    }
    int ans=cnt2+cnt4;  //原来放四个的只放了两个的可以隔一个座位再放一个的，放两个的没放满的也可以放一个
    for(int i=1; i<=k; i++)
    {
        ans-=a[i];
    }
    if(ans<0)
        puts("NO");
    else
        puts("YES");
    return 0;
}
