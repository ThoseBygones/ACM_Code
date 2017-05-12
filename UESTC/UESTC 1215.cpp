#include<iostream>
#include<cstdio>
using namespace std;

int a[5],b[5];

int main()
{
    bool flag;
    int n,t;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        bool flag=false;
        scanf("%d %d %d %d",&a[0],&a[1],&a[3],&a[2]);
        scanf("%d %d %d %d",&b[0],&b[1],&b[3],&b[2]);
        for(int j=0; j<4; j++)
        {
            if(b[0]==a[0] && b[1]==a[1] && b[2]==a[2] && b[3]==a[3])
                flag=true;
            else
            {
                t=b[3];
                b[3]=b[2];
                b[2]=b[1];
                b[1]=b[0];
                b[0]=t;
            }
        }
        if(flag)
            printf("Case #%d: POSSIBLE\n",i);
        else
            printf("Case #%d: IMPOSSIBLE\n",i);
    }
    return 0;
}
