#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#define MAXN 100005
using namespace std;

int numa[MAXN],numb[MAXN];  //��¼���������������ִ��г��ֵĴ���
int ans[MAXN];  //��¼�𰸵�����

stack <int> s;

int main()
{
    int n,m;
    int temp;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&temp);
        numa[temp%m]++;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&temp);
        numb[temp%m]++;
    }
    for(int k=0; k<2; k++)  //����ѭ������һ�����ƥ�䣨�ճ�����m-1�����ڶ���ƥ�䣨�ճ������ӽ�m-1�����֣�
    {
        for(int i=0; i<m; i++)
        {
            while(numa[i]>0)    //��һ��ƥ��ִ�У��ڶ���ƥ�䲻ִ�У�
            {
                //cout << "a=" << i << endl;
                s.push(i);
                numa[i]--;
            }
            //cout << endl;
            while(s.size() && numb[m-i-1]>0)    //��һ��ƥ�������ܴճ�����m-1ʱִ�У��ڶ���ƥ��ض�ִ�У����ƥ��ʣ�µ����֣�
            {
                ans[(m-i-1+s.top())%m]++;
                numb[m-i-1]--;
                //cout << "b=" << m-i-1 << endl;
                s.pop();
            }
        }
        //cout << "******round" << k+1 << "******" << endl;
    }
    for(int i=m-1; i>=0; i--)
    {
        while(ans[i]--)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
