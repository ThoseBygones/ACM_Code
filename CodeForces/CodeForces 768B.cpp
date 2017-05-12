#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL solve(LL x)
{
    if(x<=1)
        return 1;
    return solve(x/2)*2+1;
}

LL dfs(LL val,LL l,LL r,LL L,LL R)  //����
{
    if(R<l || L>r || val==0)    //���ڸ�����l~r��Χ�ڵ��������㣬�ڷ�Χ�ڷֽ�õ�0Ҳ������
        return 0;
    if(val==1)
        return 1;
    LL mid=solve(val/2)+L;  //��������е�
    return dfs(val/2,l,r,L,mid-1)+dfs(val%2,l,r,mid,mid)+dfs(val/2,l,r,mid+1,R);    //���ֳ�����
}

int main()
{
    LL n,l,r;
    cin >> n >> l >> r;
    LL num=solve(n);
    LL ans=dfs(n,l,r,1,num);   //�ݹ�
    cout << ans << endl;
    return 0;
}
