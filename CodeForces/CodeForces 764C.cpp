#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

struct Edge
{
    int u;
    int v;
} edge[MAXN];

int color[MAXN];    //ÿ��������ɫ
int cnt[MAXN];  //ÿ������������ڽ����ɫ��ͬ�Ĵ���
int sum;    //ȫͼ��ÿ������������ڽ����ɫ��ͬ�Ĵ���

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
        scanf("%d%d",&edge[i].u,&edge[i].v);
    for(int i=1; i<=n; i++)
        scanf("%d",&color[i]);
    for(int i=1; i<n; i++)
    {
        if(color[edge[i].u]!=color[edge[i].v])  //���ڽ����ɫ��ͬ
        {
            sum++;  //����+1
            cnt[edge[i].u]++;
            cnt[edge[i].v]++;   //�����ֱ����
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(cnt[i]==sum) //��������ô������������ڽ����ɫ��ͬ�Ĵ��� = ȫͼ��ÿ������������ڽ����ɫ��ͬ�Ĵ���
        {
            puts("YES");
            printf("%d\n",i);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
