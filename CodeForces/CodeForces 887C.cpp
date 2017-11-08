#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int a[25],b[25];
int r[6][10] = {
{1,3,5,7,9,11,24,22},
{2,4,6,8,10,12,23,21},
{1,2,18,20,12,11,15,13},
{3,4,17,19,10,9,16,14},
{13,14,5,6,17,18,21,22},
{15,16,7,8,19,20,23,24}
};

bool check()
{
    for(int i=1; i<=24; i+=4)
    {
        for(int j=i+1; j<=i+3; j++)
        {
            if(b[i]!=b[j])  //该面有一个块颜色不一样，失败
                return false;
        }
    }
    return true;
}

bool rot(int id)
{
    bool flag=false;
    for(int i=1; i<=24; i++)
        b[i]=a[i];
    for(int i=0; i<8; i++)  //右转
        b[r[id][i]]=a[r[id][(i+2)%8]];
    flag |= check();
    if(flag)
        return true;
    for(int i=0; i<8; i++)  //左转
        b[r[id][i]]=a[r[id][(i+6)%8]];
    flag |= check();
    if(flag)
        return true;
    return false;
}

int main()
{
    for(int i=1; i<=24; i++)
        scanf("%d",&a[i]);
    bool flag=false;
    for(int i=0; i<6; i++)  //枚举6种转法
    {
        flag |= rot(i);
        if(flag)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
