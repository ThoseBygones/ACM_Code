//追赶法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define INF 1e9

int main()
{
    double a,temp;
    int l,n,d;
    scanf("%lf%d",&a,&l);
    n=1;
    d=1;
    double Min=INF;
    int ansn,ansd;
    while(n<=l && d<=l)
    {
        temp=fabs(a-1.0*n/d);
        if(temp<Min)
        {
            ansn=n;
            ansd=d;
            Min=temp;
        }
        if(1.0*n/d>=a)
            d++;
        else
            n++;
    }
    printf("%d %d\n",ansn,ansd);
    return 0;
}


//二分法
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct Elem
{
    int a, b;
} ans;

double n;
int lim;

int binarysearch(int x)
{
    int l = 1;
    int r = min(lim, x * 10);
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid * 1.0 / x < n)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return mid;
}

void make(int a, int b)
{
    if (abs(a * 1.0 / b - n) < abs(ans.a * 1.0 / ans.b - n))
    {
        ans.a = a;
        ans.b = b;
    }
}

int main()
{
    //freopen("t.txt", "r", stdin);
    scanf("%lf%d", &n, &lim);
    ans.a = (int)(n + 0.5);
    ans.b = 1;
    if (ans.a == 0)
        ans.a = 1;
    if (ans.a > lim)
        ans.a = lim;
    for (int i = 2; i <= lim; i++)
    {
        int x = binarysearch(i);
        make(x, i);
        if (x > 1)
            make(x - 1, i);
    }
    printf("%d %d\n", ans.a, ans.b);
    return 0;
}
