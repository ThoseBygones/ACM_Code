#include <iostream>
#include <algorithm>
#define MAXN 100005
#define INF 1e9+7
using namespace std;

//确定区间的左右边界（点）
void checkRange(int xy, int ab, int wh, double &left, double &right)
{
    if(ab==0)
    {
        if(xy<=0 || xy>=wh)  //该方向速度为零，且该方向不在范围内，则不会进入相机范围
            right=left-1;
    }
    else if(ab>0)
    {
        left=max(left,-(double)xy/ab);  //求左端点，因为速度方向为正，求进入范围的时刻则需要在初始坐标xy前加个负号
        right=min(right,(double)(wh-xy)/ab);    //求右端点
    }
    else
    {
        left=max(left,(double)(wh-xy)/ab);  //求左端点
        right=min(right,-(double)xy/ab);    //求右端点，因为速度方向为负，求离开范围的时刻则需要在初始坐标xy前加个负号
    }
}

struct MeteorStatus
{
    double x;   //位置坐标
    int status; //0表示左边界点，1表示右边界点
    bool operator < (const MeteorStatus& a) const
    {
        if(x==a.x)
            return status>a.status; //若某一个区间的右边界与另一个左边界重合，则先处理右边界，避免重复计算出错
        return x<a.x;
    }
} ms[MAXN*2];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int w,h,n,pt=0; //用于计算存入结构体的左、右边界的数量
        cin >> w >> h >> n;
        for(int i=0; i<n; i++)
        {
            int x,y,a,b;    //X=x+at,Y=y+bt,0<X<w,0<Y<h,t>=0
            cin >> x >> y >> a >> b;
            double left=0,right=INF;    //右边界初始值设定为int的最大值
            checkRange(x,a,w,left,right);   //确认x坐标的左右区间
            checkRange(y,b,h,left,right);   //确认y坐标的左右区间
            //综合后形成完整的区间
            if(left<right)
            {
                ms[pt++]=(MeteorStatus){left,0};    //记录左边界
                ms[pt++]=(MeteorStatus){right,1};   //记录右边界
            }
        }
        sort(ms,ms+pt); //排序，从左到右
        int cnt=0,ans=0;
        for(int i=0; i<pt; i++)
        {
            if(ms[i].status==0) //如果是左边界，计数+1且更新进入相机范围最大流星数
            {
                cnt++;
                ans=max(ans,cnt);
            }
            else    //如果是右边界，计数-1
                cnt--;
        }
        cout << ans << endl;
    }
    return 0;
}
