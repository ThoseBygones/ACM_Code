#include <iostream>
#include <cstdio>
using namespace std;

int vp,vd,t,f,c;

int main()
{
    while(~scanf("%d%d%d%d%d",&vp,&vd,&t,&f,&c))
    {
        if(vp>=vd)
            printf("0\n");
        else
        {
            int cnt=0;  //Ҫʹ�õı�������
            int u=vd-vp;
            double sum=0; //��¼���������й����ߵ�·��
            sum+=1.0*vp*t;  //����δ���ֵ�ʱ��
            sum+=1.0*vp*(sum/u);    //��һ����׷���Ϲ���ʱ
            while(sum<c)
            {
                cnt++;  //��һ�α���
                sum+=1.0*vp*(f+sum/vd); //������ȥ������tСʱ
                sum+=1.0*vp*(sum/u);    //���ֹ�����׷����
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
