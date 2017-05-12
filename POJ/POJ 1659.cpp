#include <iostream>
#include <cstring>
#include <algorithm>
#define N 15
using namespace std;

struct Lake
{
    int id; //���㣨�����ı��
    int degree; //���㣨�����Ķ�
    bool operator <(const Lake &a) const    //����>������������ʱ��ʹ��
    {
        return degree>a.degree;
    }
} lake[N];

int edge[N][N]; //�ڽӾ���
bool flag;  //�Ƿ������Ŀ��ѯ�ʵ�������ϵ���жϱ�־

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        memset(edge,0,sizeof(edge));
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> lake[i].degree;
            lake[i].id=i;
        }
        flag=true;
        while(true) //����Havel-Hakimi�������
        {
            sort(lake,lake+n);  //�Խṹ�尴�Ӵ�С����
            if(lake[0].degree==0)   //���ݶ�����������Ķ���Ķȶ�Ϊ����������ѭ��
                break;
            for(int i=0; i<lake[0].degree; i++)
            {
                lake[i+1].degree--;
                if(lake[i+1].degree<0)    //���ݶ������ĳһ����Ķ�С�����򲻴�����Ŀ��ѯ�ʵ�������ϵ
                {
                    flag=false;
                    break;
                }
                edge[lake[0].id][lake[i+1].id]=edge[lake[i+1].id][lake[0].id]=1;    //���ݶ����������������ڽӾ����ϱ��1
            }
            lake[0].degree=0;   //�´�����֮ǰ�����Ķ���Ķ���0
        }
        if(flag)
        {
            cout << "YES" << endl;
            for(int i=0; i<n; i++)
            {
                cout << edge[i][0];
                for(int j=1; j<n; j++)
                    cout << " " << edge[i][j];
                cout << endl;
            }
        }
        else
            cout << "NO" << endl;
        if(t)
            cout << endl;   //ע�⣬���������������֮�����һ�����У�
    }
    return 0;
}
