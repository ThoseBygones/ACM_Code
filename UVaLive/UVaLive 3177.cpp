#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n,want[MAXN],left[MAXN],right[MAXN];    //���һ�����õ��Ǳ��1~want[i]�ŵ�ѫ�£����������Ϊ1~want[i]��������Ϊ(want[i]+1)~n

bool enough(int m)  //left,right�������¼ÿ��������������ȡ��ѫ��������
{
    int x=want[1];
    int y=m-want[1];
    left[1]=x;
    right[1]=0;
    for(int i=2; i<=n; i++) //����һ�����õ�ѫ�±���Ѿ�����
    {
        if(i%2) //���Ϊ�������˾������������ѫ��
        {
            right[i]=min(y-right[i-1],want[i]); //��ֻȡ�������ڵ�ѫ���Ѿ���������������Ҫ�ٴ������䲹��
            left[i]=want[i]-right[i];
        }
        else    //���Ϊż�����˾������������ѫ��
        {
            left[i]=min(x-left[i-1],want[i]);   //��ֻȡ�������ڵ�ѫ���Ѿ���������������Ҫ�ٴ������䲹��
            right[i]=want[i]-left[i];
        }
    }
    if(left[n]==0)  //���һ������ȡ��ѫ�±�����һ����������ͻ����Ϊ��һ������ȡ��ѫ��ȫ�������������ڣ��������һ������ֻҪ����Ҫ����������ȡѫ�£������ж�ѫ������������ĿҪ��
        return true;
    return false;
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&want[i]);
        if(n==1)    //n=1ʱֱ��������������Ҫ��ѫ�����������
        {
            printf("%d\n",want[1]);
            continue;
        }
        want[n+1]=want[1];  //����һ��������Ҫ��ѫ����������������n+1�������У��𵽹��컷������
        int l=0,r=0;
        for(int i=1; i<=n; i++)
            l=max(l,want[i]+want[i+1]); //��߽�Ϊ������������Ҫ��ѫ�����������֮�͵����ֵ
        if(n%2) //��������������ż�������ر���
        {
            for(int i=1; i<=n; i++)
                r=max(r,want[i]*3); //�ұ߽�Ϊĳ������Ҫ��ѫ�����������*3
            while(l<=r) //���ַ�����Ҫ��ѫ���������������Сֵ
            {
                int mid=(l+r)/2;
                if(enough(mid))
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}
