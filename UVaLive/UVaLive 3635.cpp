//感谢林敏轩大神给我讲解二分法（逼近）求值
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
        sum+=area[i]/value; //遍历所有的派，将每块派能被分成value面积的块数累加
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
            maxArea=max(maxArea,area[i]);   //记录派的最大面积
        }
        double left=0,right=maxArea;    //二分法：初始化左值为0，右值为maxArea
        while(right-left>ERROR) //当左右值之差在误差范围内时不再二分
        {
            double mid=(left+right)/2;  //二分法求中值
            if(satisfyNeed(mid))    //如果中值能满足要求（即中值表示的面积能分给所有人）
                left=mid;   //继续搜索中值到右值之间的面积范围（看看面积是否还能更大？）
            else
                right=mid;  //继续搜索左值到中值之间的面积范围（看看这个范围能不能满足要求）
        }
        cout << fixed << setprecision(4) << left << endl;
    }
    return 0;
}
