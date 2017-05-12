#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define MAXN 200005

int fa[MAXN];
int c[MAXN];    //���ӵ���ɫ
int id[MAXN];   //���ϵı��
int n,m,k;

vector <int> num[MAXN]; //��¼���е��Ӧ�ĸ��ڵ���ɫ�ı��
map <int,int> cnt;  //��¼ÿ�����ڵ���ӳ��ÿ�����ڵ���ֵĴ���

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

void unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
        fa[xx]=yy;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        fa[i]=i;
    for(int i=1; i<=n; i++)
        scanf("%d",&c[i]);
    for(int i=1; i<=m; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        unionset(l,r);  //��Ҫ��ͬһ�촩����������
    }
    for(int i=1; i<=n; i++)
        num[findset(i)].push_back(c[i]);
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        cnt.clear();
        int Max=0;
        int sz=num[i].size();
        //if(sz<=1) //���鼯��ĵ�����С��1���������㣨��һ����д�ɲ�д��
        //    continue;
        for(int j=0; j<sz; j++)
        {
            cnt[num[i][j]]++;   //��¼������ɫ���ӵĸ���
            Max=max(Max,cnt[num[i][j]]);    //Ѱ��ͬһ��ɫ��������
        }
        ans+=sz-Max;    //ÿ�ν�ʣ�������Ⱦɫ�������Ǹ���ɫ����
    }
    printf("%d\n",ans);
    return 0;
}
