#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAXN 1005
#define LL long long
#define INF 0x3f3f3f3f
#define MOD 1000000007

bool leapYear(int y)
{
    if((y%4==0 && y%100!=0) || y%400==0)
        return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int y,m,d;
        scanf("%d-%d-%d",&y,&m,&d);
        int cnt=0;
        while(true)
        {
            if(m==2 && d==29)
            {
                cnt=(cnt+7-1)%7;
                while(!leapYear(y+1))
                {
                    cnt=(cnt+365%7)%7;
                    y++;
                    //cout << "#" << y << endl;
                }
                //system("pause");
                cnt=(cnt+366%7)%7;
                cnt=(cnt+1)%7;
                //cout << cnt << endl;
            }
            else if(m>=3)
            {
                if(leapYear(y+1))
                    cnt=(cnt+366%7)%7;
                else
                    cnt=(cnt+365%7)%7;
            }
            else
            {
                if(leapYear(y))
                    cnt=(cnt+366%7)%7;
                else
                    cnt=(cnt+365%7)%7;
            }
            y++;
            if(cnt==0)
                break;
        }
        printf("%d\n",y);
    }
    return 0;
}
