#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 200005
#define INF 0x3f3f3f3f

vector <int> v[MAXN];   //��¼ÿ������Ͷ���ֵ
pair <int,int> PII;
set < pair <int,int> > s;   //set��Ԫ�ص������Ǹ���pair�еĵ�һ����ֵ�����

int Max[MAXN];    //��¼ÿ����Ͷ������ֵ
int del[MAXN];  //��¼ÿ��������ɾ������

//PII pos1,pos2;

struct Node
{
    int id;
    int val;
} p[MAXN];

int main()
{
    int n,q;
    scanf("%d",&n);
    memset(Max,0,sizeof(Max));
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&p[i].id,&p[i].val);
        v[p[i].id].push_back(p[i].val);
        Max[p[i].id]=max(p[i].val,Max[p[i].id]);
    }
    for(int i=1; i<=n; i++)
    {
        if(Max[i])
            s.insert(make_pair(Max[i],i));  //�����Ͷ�꣬���ڼ����в�������Ͷ���������Ͷ����
    }
    scanf("%d",&q);
    for(int i=1; i<=q; i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1; j<=k; j++)
        {
            scanf("%d",&del[j]);
            if(Max[del[j]])
                s.erase(make_pair(Max[del[j]],del[j]));   //���ɾ�����Ǹ�����ͶƱ��Ĩȥ���ļ�¼
        }
        if(!s.size())   //���������ɶҲ��ʣ�ˣ���ȫ������Ĩȥ��
            printf("0 0\n");
        else if(s.size()==1)    //���������ֻʣһ�����ˣ���ô������С��һ��Ͷ�������
            printf("%d %d\n",s.begin()->second,*v[s.begin()->second].begin());
        else
        {
            auto pos1=s.end();
            auto pos2=s.end();
            pos1--; //����
            pos2--,pos2--;    //�ڶ����
            int val=pos2->first;   //����ֵ
            int index=pos1->second;  //���ֵ��ӦͶ���ߵı��
            auto it=upper_bound(v[index].begin(),v[index].end(),val);   //���ֲ���
            printf("%d %d\n",index,*it);
        }
        for(int j=1; j<=k; j++) //�ô�ѯ�ʽ������ѱ�ɾ���Ĳ���ȥ
        {
            if(Max[del[j]])
                s.insert(make_pair(Max[del[j]],del[j]));
        }
    }
    return 0;
}
