#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    while(~scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f))
    {
        if(a==0 && b==0 && c==0 && d==0 && e==0 && f==0)
            break;
        int ans=f+e+d+(c+3)/4;  //每个6*6的箱子只能装下1个6*6或1个5*5或1个4*4或者4个3*3的箱子
        int x=d*5;  //装了6*6和5*5物品的箱子都装不下2*2的物品，只有装了4*4物品的箱子还能装下5个2*2的物品
        if(c%4==3)
            x+=1;
        else if(c%4==2)
            x+=3;
        else if(c%4==1)
            x+=5;
        if(x<b) //挪出来的空位还不够装下所有2*2的箱子
            ans+=(b-x+8)/9;
        int y=36*ans-36*f-25*e-16*d-9*c-4*b;    //可用的所有空间减去已用的空间求出可放1*1物品的空间数
        if(y<a)
            ans+=(a-y+35)/36;
        printf("%d\n",ans);
    }
    return 0;
}
