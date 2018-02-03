#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int a[50];
set <int> s;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        a[i]%=m;
    }
    sort(a,a+n);
    int p1=n/2;
    int p2=n-p1;
    for(int i=0; i<(1<<p1); i++)
    {
        int temp=0;
        for(int j=0; j<p1; j++)
        {
            if((1<<j)&i)
                temp=(temp+a[j])%m;
        }
        s.insert(temp);
    }
    int ans=0;
    set<int>::iterator it;
    for(int i=0; i<(1<<p2); i++)
    {
        int temp=0;
        for(int j=0; j<p2; j++)
        {
            if((1<<j)&i)
                temp=(temp+a[p1+j])%m;
        }
        it=s.upper_bound(m-temp-1); //最大不能超过m-1
        if(it==s.begin())   //如果没有找到合适的也要更新ans值
            ans=max(ans,temp);
        else
        {
            it--;   //因为使用的是upper_bound，所以要回退一个
            ans=max(ans,temp+(*it));
        }
    }
    printf("%d\n",ans);
    return 0;
}
