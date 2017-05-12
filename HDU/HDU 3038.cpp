//���ǲ��鼯�ܳ�����һ�����͡������������ò��鼯�޷�������ʵ���Ͽ���ת�������ಢ�鼯
//����A~B֮�������֮��ΪS����������B��A-1��S����ǰB��Ԫ��֮�ͱ�ǰA-1��Ԫ��֮�ʹ�S
//�������Ϳ��԰��ճ�������ಢ�鼯����
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 200005
using namespace std;

int par[MAXN],sum[MAXN];    //sum�����¼��
int n,m;
int ans;

int findset(int r)
{
    if(r!=par[r])
    {
        int temp=par[r];
        par[r]=findset(par[r]); //Ѱ�Ҹ��ڵ㣬���Ѹõ�ĸ��ڵ�ָ����ڵ�
        sum[r]+=sum[temp];  //�ۼ�Ѱ�ҹ����е��Ӷκ�
    }
    return par[r];
}

void mergeset(int x,int y,int s)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx==yy)  //�����ڵ���ͬ
    {
        if(sum[y]-sum[x]!=s)    //����x��������y�����ĺͣ���ǰy�����ĺ���ǰx-1�����ĺ͵Ĳ��֮ǰ��¼��ì�ܣ�����һ������Ĵ�
        {
            ans++;
            return ;
        }
    }
    else if(xx>yy)
    {
        par[xx]=yy; //������ֵС�Ľڵ���
        sum[xx]=sum[y]-sum[x]-s;    //�����ĺͼ�¼����ֵ��Ľڵ���
    }
    else if(xx<yy)
    {
        par[yy]=xx; //������ֵС�Ľڵ���
        sum[yy]=sum[x]-sum[y]+s;    //�����ĺͼ�¼����ֵ��Ľڵ���
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<=n; i++)
        {
            par[i]=i;
            sum[i]=0;
        }
        ans=0;
        while(m--)
        {
            int a,b,s;
            scanf("%d%d%d",&a,&b,&s);
            a--;    //��a��ȥһ����ά��a-1��b֮������ִ�
            mergeset(a,b,s);
        }
        printf("%d\n",ans);
    }
    return 0;
}
