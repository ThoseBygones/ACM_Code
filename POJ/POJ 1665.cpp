#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define PI 3.1415927

int main()
{
    double dia,t,wr,dist,speed;
    int rev,cnt=0;
    while(cin >> dia >> rev >> t)
    {
        if(rev==0)
            break;
        wr=PI*dia/12/5280;
        dist=wr*rev;
        speed=dist/t*60*60;
        cnt++;
        printf("Trip #%d: %.2lf %.2lf\n",cnt,dist,speed);
    }
    return 0;
}
