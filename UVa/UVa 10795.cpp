#include <iostream>
#include <cmath>
#define LL long long
using namespace std;

int n,start[65],terminal[65];

LL mov(int now[],int k,int target)
{
    if(k==0)
        return 0;
    if(now[k]==target)
        return mov(now,k-1,target); //如果要移动的这个盘子已经在目标柱子上了就不移动它
    return mov(now,k-1,6-now[k]-target)+(LL)pow(2,k-1); //否则先将其他所有比它小的盘子都移到除这个盘子所在的柱子和这个盘子将要移到的目标柱子以外的柱子（例如k号盘子在柱子3要移到柱子1，则将所有小于k的盘子移到柱子2按从上到下递增的次序堆成一堆），然后加上已经按次序堆好的k号盘子移动到目标柱子的1步，再加上将已经按次序堆好的所有小于k的所有盘子移动到目标柱子的2^(k-1)-1步
}

int main()
{
    int kase=1;
    while(cin >> n,n)
    {
        int num=n;  //从最大的盘子开始向下遍历
        LL ans=0;
        for(int i=1; i<=n; i++)
            cin >> start[i];
        for(int i=1; i<=n; i++)
            cin >> terminal[i];
        while(start[num]==terminal[num])    //如果该盘子已经在目标柱子上了，则对比它小一号的盘子进行同样的判断
            num--;
        if(num>0)
            ans=mov(start,num-1,6-terminal[num]-start[num])+1+mov(terminal,num-1,6-terminal[num]-start[num]);   //当前状态移动到某分界状态所需的步数+还未移动到目标柱子的最大号的盘子的1步+从某分界状态移动到目标状态所需的步数
        cout << "Case " << kase++ << ": " << ans << endl;
    }
    return 0;
}
