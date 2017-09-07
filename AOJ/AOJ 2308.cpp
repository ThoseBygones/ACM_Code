#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 55
#define EPS 1e-6
#define g 9.8
#define PI acos(-1)

struct Obstacle
{
    int l;
    int r;
    int t;
    int b;
} ob[MAXN];

int n,v,tx,ty;
double a,b,c;

void getabc(double angle)
{
    double vx = v * cos(angle); //x轴方向速度
    double vy = v * sin(angle); //y轴方向速度
    a = -0.5 * g / (vx * vx);
    b = vy / vx;
    c = 0;
}

bool check1(double x, double up, double down)    //是否会撞到障碍物的左（右）顶端或者左（右）底端
{
    if(x >= tx)   //如果障碍物的x坐标在猪的x坐标的右侧，则就算会撞到也不要紧（扔炸弹杀死猪不受该障碍物影响）
        return false;
    double y = a * x * x + b * x + c;   //求出相应的y坐标
    if(up <= y && y <= down)    //会撞到
        return true;
    return false;
}

bool check2(double y, double left, double right)
{
    double delta = b * b - 4 * a * y;
    if(delta < 0)   //抛物线与障碍物上（下）的左端和右端形成的线段没有交点，则不会相撞
        return false;
    delta = sqrt(delta);
    double x1 = (-b + delta) / (2 * a);
    double x2 = (-b - delta) / (2 * a);
    if(x1 < tx && left <= x1 && x1 <= right)    //如果抛物线与障碍物上（下）的左端点有交点且交点的x坐标在猪的左边，则无法杀死猪
        return true;
    if(x2 < tx && left <= x2 && x2 <= right)    //如果抛物线与障碍物上（下）的右端点有交点且交点的x坐标在猪的左边，则无法杀死猪
        return true;
    return false;
}

bool check3(double x, double y, double h, double t, double l, double r)
{
    if(l <= x && x <= r && y <= t && t <= h)    //如果障碍正好挡在白鸟飞行的抛物线轨迹和猪的中间，则炸蛋无法击中猪
        return true;
    return false;
}

bool check(double angle)
{
    getabc(angle);
    double h = a * tx * tx + b * tx + c;
    if(h < ty)    //飞不到猪的上方，则不可能杀死猪
        return false;
    for(int i=0; i<n; i++)
    {
        if(check1(ob[i].l,ob[i].b,ob[i].t))
            return false;
        if(check1(ob[i].r,ob[i].b,ob[i].t))
            return false;
        if(check2(ob[i].b,ob[i].l,ob[i].r))
            return false;
        if(check2(ob[i].t,ob[i].l,ob[i].r))
            return false;
        if(check3(tx,ty,h,ob[i].b,ob[i].l,ob[i].r))
            return false;
        //if(check3(tx,ty,h,ob[i].t,ob[i].l,ob[i].r))
        //    return false;
    }
    return true;
}

bool solve()
{
    for(double i=0; i<0.5*PI; i+=0.000001)
    {
        if(check(i))
            return true;
    }
    return false;
}

int main()
{
    scanf("%d%d%d%d",&n,&v,&tx,&ty);
    for(int i=0; i<n; i++)
        scanf("%d%d%d%d",&ob[i].l,&ob[i].b,&ob[i].r,&ob[i].t);
    if(solve())
        puts("Yes");
    else
        puts("No");
    return 0;
}
