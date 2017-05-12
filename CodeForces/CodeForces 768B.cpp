#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL solve(LL x)
{
    if(x<=1)
        return 1;
    return solve(x/2)*2+1;
}

LL dfs(LL val,LL l,LL r,LL L,LL R)  //分治
{
    if(R<l || L>r || val==0)    //不在给定的l~r范围内的数不计算，在范围内分解得到0也不计数
        return 0;
    if(val==1)
        return 1;
    LL mid=solve(val/2)+L;  //求出区间中点
    return dfs(val/2,l,r,L,mid-1)+dfs(val%2,l,r,mid,mid)+dfs(val/2,l,r,mid+1,R);    //划分成三个
}

int main()
{
    LL n,l,r;
    cin >> n >> l >> r;
    LL num=solve(n);
    LL ans=dfs(n,l,r,1,num);   //递归
    cout << ans << endl;
    return 0;
}
