#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int x[5],y[5];

int main()
{
    int t,n;
    double area,gx,gy,areasum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        scanf("%d %d %d %d",&x[1],&y[1],&x[2],&y[2]);
        n -= 2;
        gx = gy = areasum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d",&x[3],&y[3]);
            area = ((x[2] - x[1]) * (y[3] - y[1]) - (x[3] - x[1]) * (y[2] - y[1])) / 2.0;
            gx += ((x[1] + x[2] + x[3]) * area);
            gy += ((y[1] + y[2] + y[3]) * area);
            areasum += area;
            x[2] = x[3];
            y[2] = y[3];
        }
        printf("%.2lf %.2lf\n",gx / areasum / 3.0,gy / areasum / 3.0);
    }
    return 0;
}
