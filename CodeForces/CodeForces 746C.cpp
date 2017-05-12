#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,x1,x2;
    int t1,t2;
    int p,d;
    int time1,time2;
    scanf("%d%d%d",&s,&x1,&x2);
    scanf("%d%d",&t1,&t2);
    scanf("%d%d",&p,&d);
    time1=t2*abs(x2-x1);
    if(d==1)
    {
        if(p<=x1 && x1<x2)
            time2=(x2-p)*t1;
        else if(x1<x2)
            time2=(2*s-p+x2)*t1;
        else
            time2=(2*s-p-x2)*t1;
    }
    else
    {
        if(p>=x1 && x1>x2)
            time2=(p-x2)*t1;
        else if(x1>x2)
            time2=(2*s+p-x2)*t1;
        else
            time2=(p+x2)*t1;
    }
    printf("%d\n",min(time1,time2));
    return 0;
}
