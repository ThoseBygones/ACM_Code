#include <bits/stdc++.h>
using namespace std;

/*
我们关心的不仅只有最大值，还有次大的。
一组数字，没有修改的话原本的贡献是相同的，所以问题就变成了去掉一个数最多能增加（减少）多少贡献；
如果有一个数比它前面最大数都大，那么去掉它会产生负贡献；
如果它比前面的次大值大，比最大值小，那么去掉前面的最大值会增加一个贡献；
建一个cnt数组，cnt[i]表示去掉其所增加的贡献；
*/

#define MAXN 100005
#define LL long long

int a[MAXN],rec[MAXN];  //去掉该下标元素后，record的增加量

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int max1=0,max2=0;  //最大值，次大值
    for(int i=1; i<=n; i++)
    {
        if(a[i]>max1)   //更新最大值和次大值
        {
            max2=max1;
            max1=a[i];
            rec[a[i]]--;
        }
        else if(a[i]>max2)  //只更新次大值
        {
            max2=a[i];
            rec[max1]++;
        }
    }
    int Max=-2; //最小为-1（即最大值在最后的情况）
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(rec[i]>Max)
        {
            Max=rec[i];
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
