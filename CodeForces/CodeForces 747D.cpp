#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int tem[MAXN];

priority_queue <int, vector<int>, greater<int> > pq;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&tem[i]);
        if(tem[i]<0)
            cnt++;
    }
    if(cnt>k)
    {
        puts("-1");
        return 0;
    }
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        if(tem[i]<0 && tem[i-1]>=0) //̰�ģ����ܻ��ͻ�����֤�϶��ܰ��ȹ���
            sum+=2;
    }
    int s=0;
    for(int i=1; i<=n; i++)
    {
        if(tem[i]<0)
        {
           s=i;
           break;
        }
    }
    int con=0;    //ÿ��������ȵ�ʱ��γ�����ʱ��
    for(int i=1; i<=n; i++)
    {
        if(tem[i]>=0)   //�����¶ȸ߹����ʱ
        {
            if(tem[i-1]<0)  //ǰһ���¶Ȼ��������
                con=1;
            else    //ǰһ���¶�Ҳ�������
                con++;
        }
        else    //�����¶ȵ������
        {
            if(con)
            {
                pq.push(con);
                con=0;
            }
        }
    }
    //if(con)
    //    pq.push(con);   //�������һ��
    int temp=cnt;   //�ܻ��ͻ�ʱ������̥ʹ������
    while(!pq.empty())
    {
        if(temp+pq.top()<=k)    //������С��һ���¶ȸ�����ȵ�ʱ���Ҳ����ʹ�ö�����̥��ʹ�ö�����̥����ʱ�仹δ����������̥��ʹ������
        {
            temp+=pq.top();
            pq.pop();
            sum-=2; //�ٻ�����
        }
        else
            break;
    }
    if(temp+con<=k)
        sum--;  //�������һ�Σ����һ���������Ҳֻ���ٻ�һ��
    printf("%d\n",sum);
    return 0;
}
