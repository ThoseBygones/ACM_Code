//��л������������ҽ�����ַ����ƽ�����ֵ
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define PI acos(-1)
#define ERROR 1e-4
using namespace std;

double area[10005];
int n,f;

bool satisfyNeed(double value)
{
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=area[i]/value; //�������е��ɣ���ÿ�����ܱ��ֳ�value����Ŀ����ۼ�
    if(sum>=f+1)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> f;
        double maxArea=-1;
        for(int i=0; i<n; i++)
        {
            double r;
            cin >> r;
            area[i]=PI*r*r;
            maxArea=max(maxArea,area[i]);   //��¼�ɵ�������
        }
        double left=0,right=maxArea;    //���ַ�����ʼ����ֵΪ0����ֵΪmaxArea
        while(right-left>ERROR) //������ֵ֮������Χ��ʱ���ٶ���
        {
            double mid=(left+right)/2;  //���ַ�����ֵ
            if(satisfyNeed(mid))    //�����ֵ������Ҫ�󣨼���ֵ��ʾ������ָܷ������ˣ�
                left=mid;   //����������ֵ����ֵ֮��������Χ����������Ƿ��ܸ��󣿣�
            else
                right=mid;  //����������ֵ����ֵ֮��������Χ�����������Χ�ܲ�������Ҫ��
        }
        cout << fixed << setprecision(4) << left << endl;
    }
    return 0;
}
