#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define MAXM 100005

int fa[MAXN];
int num[MAXN];  //����ͨ�����а����Ľ�������
int gov[MAXN];  //�Ƿ�Ϊ�������
int n,m,k;

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

int unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        num[yy]+=num[xx];   //�ϲ����ʱͳ�ƽ������
        if(gov[xx])
            gov[yy]=1;
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
    {
        fa[i]=i;
        num[i]=1;
        gov[i]=0;
    }
    while(k--)
    {
        int c;
        scanf("%d",&c);
        gov[c]=1;   //����������
    }
    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        unionset(u,v);
    }
    int cnt=0;  //��������������ͨ��������
    int res=0;  //��������������ͨ�����ڽ����
    int ans=0;  //�ܵ���Ҫ�����ı���
    for(int i=1; i<=n; i++)
    {
        if(fa[i]==i)
        {
            if(!gov[i]) //��������������ͨ�����������
                cnt+=num[i];
            else    //��������������ͨ����ѡ���������������
            {
                res=max(res,num[i]);
                ans+=num[i]*(num[i]-1)/2; //�ۼ�ÿ����������������ͨ��������Ҫ���ϵ��ܱ���
            }
        }
    }
    cnt+=res;
    ans-=res*(res-1)/2; //��ȥ�ظ������˵ı�ѡ�еİ�������������ͨ�������ܱ���
    ans+=cnt*(cnt-1)/2-m;   //�ټ��ϲ�������������ͨ�������ܱ���
    printf("%d\n",ans);
    return 0;
}
