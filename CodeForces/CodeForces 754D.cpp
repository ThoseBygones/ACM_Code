#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN (int)3e5+10

struct Coupon
{
    int id;
    int l;
    int r;
} cp[MAXN];

bool cmp(Coupon a,Coupon b)
{
    return a.l<b.l;
}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&cp[i].l,&cp[i].r);
            cp[i].id=i+1;
        }
        sort(cp,cp+n,cmp);  //按照优惠范围的左端点从小到大排序
        priority_queue < int, vector<int>, greater<int> > pq;
        int ans=0;
        int p=0;  //记录下标
        for(int i=0; i<n; i++)
        {
            pq.push(cp[i].r);   //只需要右端点入队即可（左端点已经有序）
            if(pq.size()>k) //维护大小为k的队列（超过就弹出最小的）
                pq.pop();
            //cout << "#" << pq.top() << endl;
            int temp=pq.top()-cp[i].l+1;    //top指向优先队列（堆）中右端点最小的，其与左端点中最大的（左端点已经有序）的差即为区间的并集
            if(pq.size()==k && temp>ans)    //求出最大值
            {
                ans=temp;
                p=cp[i].l;
            }
        }
        printf("%d\n",ans);
        if(!ans)
        {
            printf("1");
            for(int i=2; i<=k; i++)
                printf(" %d",i);
            printf("\n");
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(cp[i].l<=p && cp[i].r>=p+ans-1)
                {
                    if(k>1)
                        printf("%d ",cp[i].id);
                    else
                    {
                        printf("%d\n",cp[i].id);
                        break;
                    }
                    k--;
                }
            }
        }
    }
    return 0;
}
