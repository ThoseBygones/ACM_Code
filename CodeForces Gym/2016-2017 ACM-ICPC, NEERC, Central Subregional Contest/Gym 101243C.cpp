#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define PII pair <int,int>

vector <pair <int,int> > v;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int h,w;
    scanf("%d%d",&h,&w);
    if(h<2 || w<2)
    {
        puts("0");
        return 0;
    }
    if(h%2==0)
    {
        for(int i=1; i<=h-1; i+=2)  //�м䲻����
        {
            for(int j=1; j<=w-2; j++)   //���һ�в���
                v.push_back(make_pair(i,j));
        }
        for(int i=1; i<=h-1; i++)  //���Ͻ���ŵ����һ��
            v.push_back(make_pair(i,w-1));
    }
    else if(w%2==0)
    {
        for(int i=1; i<=w-1; i+=2)  //�м䲻����
        {
            for(int j=1; j<=h-2; j++)   //���һ�в���
                v.push_back(make_pair(j,i));
        }
        for(int i=1; i<=w-1; i++)   //���Ͻ���ŵ����һ��
            v.push_back(make_pair(h-1,i));
    }
    else
    {
        for(int i=1; i<=w-1; i+=2)  //��һ���м��Ȳ������
            v.push_back(make_pair(1,i));
        for(int i=2; i<=h-1; i+=2)   //�൱�ڻ�����Ϊż�����ӵڶ��п�ʼ�м佻���
        {
            for(int j=1; j<=w-2; j++)   //���һ�в���
                v.push_back(make_pair(i,j));
        }
        for(int i=2; i<=h-1; i++)   //��һ�в��ţ������һ�����һ�ž�ֻʣ���Ͻ���
            v.push_back(make_pair(i,w-1));  //���Ͻ���ŵ����һ��
    }
    int ans=v.size();
    printf("%d\n",ans);
    for(int i=0; i<v.size(); i++)
        printf("%d %d\n",v[i].first,v[i].second);
    return 0;
}
