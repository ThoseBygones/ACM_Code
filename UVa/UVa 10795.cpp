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
        return mov(now,k-1,target); //���Ҫ�ƶ�����������Ѿ���Ŀ���������˾Ͳ��ƶ���
    return mov(now,k-1,6-now[k]-target)+(LL)pow(2,k-1); //�����Ƚ��������б���С�����Ӷ��Ƶ�������������ڵ����Ӻ�������ӽ�Ҫ�Ƶ���Ŀ��������������ӣ�����k������������3Ҫ�Ƶ�����1��������С��k�������Ƶ�����2�����ϵ��µ����Ĵ���ѳ�һ�ѣ���Ȼ������Ѿ�������Ѻõ�k�������ƶ���Ŀ�����ӵ�1�����ټ��Ͻ��Ѿ�������Ѻõ�����С��k�����������ƶ���Ŀ�����ӵ�2^(k-1)-1��
}

int main()
{
    int kase=1;
    while(cin >> n,n)
    {
        int num=n;  //���������ӿ�ʼ���±���
        LL ans=0;
        for(int i=1; i<=n; i++)
            cin >> start[i];
        for(int i=1; i<=n; i++)
            cin >> terminal[i];
        while(start[num]==terminal[num])    //����������Ѿ���Ŀ���������ˣ���Ա���Сһ�ŵ����ӽ���ͬ�����ж�
            num--;
        if(num>0)
            ans=mov(start,num-1,6-terminal[num]-start[num])+1+mov(terminal,num-1,6-terminal[num]-start[num]);   //��ǰ״̬�ƶ���ĳ�ֽ�״̬����Ĳ���+��δ�ƶ���Ŀ�����ӵ����ŵ����ӵ�1��+��ĳ�ֽ�״̬�ƶ���Ŀ��״̬����Ĳ���
        cout << "Case " << kase++ << ": " << ans << endl;
    }
    return 0;
}
