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
        sort(cp,cp+n,cmp);  //�����Żݷ�Χ����˵��С��������
        priority_queue < int, vector<int>, greater<int> > pq;
        int ans=0;
        int p=0;  //��¼�±�
        for(int i=0; i<n; i++)
        {
            pq.push(cp[i].r);   //ֻ��Ҫ�Ҷ˵���Ӽ��ɣ���˵��Ѿ�����
            if(pq.size()>k) //ά����СΪk�Ķ��У������͵�����С�ģ�
                pq.pop();
            //cout << "#" << pq.top() << endl;
            int temp=pq.top()-cp[i].l+1;    //topָ�����ȶ��У��ѣ����Ҷ˵���С�ģ�������˵������ģ���˵��Ѿ����򣩵ĲΪ����Ĳ���
            if(pq.size()==k && temp>ans)    //������ֵ
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
