#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int kase=1;
    while(t--)
    {
        double a,b;
        bool flag=false;
        scanf("%lf%lf",&a,&b);
        if(b==10 || b==1 || b==0.1 || b==0.01)
            flag=true;
        if(a==b*2)
            flag=false;
        printf("Case #%d: ",kase++);
        if(flag)
            printf("0.02\n");
        else
            printf("0.01\n");
    }
    return 0;
}
