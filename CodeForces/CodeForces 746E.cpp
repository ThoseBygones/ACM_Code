#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 200005

int a[MAXN];
map <int,int> vis;  //��¼д��ĳ�����ֵĿ����ǲ����Ѿ�ӵ��
int cnt[2];  //��¼����ż�����Ƶ�����
vector <int> v;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(vis[a[i]] || cnt[(a[i]&1)]==n/2) //��������ظ���������ż���������������������¼�����Ա�֮�����任
            v.push_back(i);
        else
        {
            vis[a[i]]=1;
            cnt[(a[i]&1)]++;
        }
    }
    int cnum=0;  //�����䶯�Ŀ��Ƶ�����
    for(int i=1; i<=m; i++)
    {
        if(cnum==v.size())
            break;
        if(!vis[i]) //ĳ����ŵĿ��ƻ�ûӵ��
        {
            if(cnt[(i&1)]<n/2)  //�ÿ��ƶ�Ӧ������ż�����Ŀ�������δ��
            {
                cnt[(i&1)]++;
                a[v[cnum]]=i;  //�滻�ÿ���
                cnum++;
            }
        }
    }
    if(cnum<v.size())
        puts("-1");
    else
    {
        printf("%d\n",cnum);
        for(int i=1; i<n; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
