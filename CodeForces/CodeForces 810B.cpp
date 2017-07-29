#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

LL k[MAXN],l[MAXN];
LL a[MAXN];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    int n,f;
    scanf("%d%d",&n,&f);
    LL sum=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&k[i],&l[i]);
        sum+=min(k[i],l[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(k[i]<l[i])   //供不应求
        {
            l[i]-=k[i];
            a[i]=min(l[i],k[i]);    //多卖多少
        }
        else    //供大于求
            a[i]=0; //再翻倍进货也无法多卖
    }
    sort(a,a+n,cmp);
    for(int i=0; i<f; i++)
        sum+=a[i];
    cout << sum << endl;
}
