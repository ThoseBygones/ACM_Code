#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define LL long long

/*
数列中不存在相同的数时，每个数对每个区间贡献度为1，贡献即为(n-i+1)*i*2；
数列中存在相同的数时，对于数a[i]，前一个相同的数a[j]已经计算了它在包含前j个数的区间的贡献，
这样我们只需要加上包含第j到第i的数的贡献，标记a[i]的前一个位置为pre[a[i]]，则贡献为(n-i+1)*(n-pre[a[i]])*2。
*/

int a[MAXN];
int pre[MAXN];  //第i个数字前一次出现的位置

int main()
{
    int n;
    scanf("%d",&n);
    memset(pre,0,sizeof(pre));
    LL ans=0;
    for(int i=1; i<=n; i++)
    {
        int val;
        scanf("%d",&val);
        ans+=(LL)(i-pre[val])*(LL)(n-i+1);
        pre[val]=i;
    }
    ans=ans*2-n;    //x与y相等的时候只有一种情况，故去掉重复计算n种可能
    printf("%.6f\n",1.0*ans/n/n);
    return 0;
}
