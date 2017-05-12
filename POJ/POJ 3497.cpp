#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <string,int> cId;
int n,b,cnt;

struct Component
{
    int price;
    int quality;
};

vector <Component> c[1005];

int arrangeId(string s)
{
    if(!cId.count(s))
        cId[s]=cnt++;   //��mapӳ��Ϊ��ͬ��������
    return cId[s];
}

bool satisfyNeed(int x) //Ʒ�ʲ�С��x������ܷ���װ��һ���۸񲻳���b�ĵ��ԣ�
{
    int sum=0;
    for(int i=0; i<cnt; i++)    //  ����ÿ�����
    {
        int cheapest=b+1;   //��������˵��������Ԥ���
        int len=c[i].size();
        for(int j=0; j<len; j++)    //����ÿ������Ĳ�ͬѡ��
        {
            if(c[i][j].quality>=x)  //ֻҪ���������������ѡ��Ʒ�ʲ���Ŀ���ֵx�ͼ��ɣ���Ϊ�������Ե������������������Ǹ���������ģ�
                cheapest=min(cheapest,c[i][j].price);   //ѡ����������˵��Ǹ�
        }
        if(cheapest==b+1)   //����˵�����һ������۸񶼱�Ԥ�㻹���򷵻�false
            return false;
        sum+=cheapest;  //�ۼ�ÿ��ѡ�е�����ļ۸�
        if(sum>b)   //��δ�����������֮ǰ�ܼ۳�����Ԥ��ͷ���false
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> b;
        cnt=0;
        for(int i=0; i<n; i++)
            c[i].clear();
        cId.clear();
        int maxQuality=0;
        string type,name;
        int p,q;
        for(int i=0; i<n; i++)
        {
            cin >> type >> name >> p >> q;
            Component temp;
            temp.price=p;
            temp.quality=q;
            maxQuality=max(maxQuality,q);
            c[arrangeId(type)].push_back(temp);   //����ͬ������ļ۸��Ʒ������ֱ�洢
        }
        int left=0,right=maxQuality;    //���ַ��󲻳���bԪ��Ԥ������װ�ɵĵ��Ե�Ʒ��
        while(left<=right)
        {
            int mid=(left+right)/2;
            //int mid=left+(right-left+1)/2;    //�������ֺܺõı�������ѭ����ֱ��������1.left<right���ɣ�2.ֻҪright=mid-1��left=mid����
            if(satisfyNeed(mid))
                left=mid+1;
            else
                right=mid-1;    //mid��ֵ�Ѿ��޷���ɣ������ֵ��Ϊmid-1
        }
        if((left+right)%2)  //����������ѭ�����ж�һ�����Ĳ�ֵ�Ƿ�Ϊ�������ǵĻ�-1
            left--;
        cout << left << endl;
    }
    return 0;
}
