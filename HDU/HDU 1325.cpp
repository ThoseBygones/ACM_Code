#include <cstdio>
#define MAXN 1005
using namespace std;

struct Node
{
    int num;
    int par;
    int indegree;//���ݡ��������
};

Node node[MAXN];

void init()
{
    for(int i = 0; i < MAXN; i++)
    {
        node[i].indegree = 0;//��ȳ�ʼ��Ϊ0
        node[i].par= i;//����¼Ϊ����
        node[i].num=0;//��������Ƿ�ʹ�ù���0:û�б�ʹ�ù���1:ʹ�ù���
    }
}

int findset(int a)
{
    if(node[a].par!=a)
        return node[a].par = findset(node[a].par);
    return node[a].par;
}

void mergeset(int a,int b)
{
    a = findset(a);
    b = findset(b);
    if(a==b)//ͬһ������˵������ͬһ������
        return;
    node[b].par=a;//��b�ĸ���Ϊa�ĸ�����ʱa�Ѿ��Ǹ���num==par
}

int main()
{
    int n,m;
    int kase = 1;
    bool flag=true;//true���Ǹ�����false:������
    init();
    while(scanf("%d%d",&n,&m)!=EOF&&n>=0&&m>=0)
    {
        if(!flag&&n!=0&&n!=0)continue;//�Ѿ�ȷ���������ˣ��ͼ���ѭ��
        if(n==0&&m==0)
        {
            int root_num=0;
            for(int j = 1; j < MAXN; j++)
            {
                //�ж��Ƿ�Ϊɭ�֣������root_num������¼������Ŀ
                if(node[j].num && findset(j)==j)
                    root_num++;
                if(node[j].indegree>1)//�������ĳ���ڵ����ȳ���1��������
                {
                    flag = false;
                    break;
                }
            }
            if(root_num>1)//��ͨ��֧����1����ɭ�ֲ�����
                flag=false;
            if(flag)
                printf("Case %d is a tree.\n",kase++);
            else printf("Case %d is not a tree.\n",kase++);
            flag = true;
            init();
            continue;
        }
        if(m!=n&&findset(n)==findset(m))
            flag = false;
        else
        {
            //��m,n����¼Ϊ�ڵ�
            node[m].num = 1;
            node[n].num = 1;
            node[m].indegree++;//�������һ
            mergeset(n,m);
        }
    }
    return 0;
}
