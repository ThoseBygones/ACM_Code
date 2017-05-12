#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(x%i==0 && x/i<=n)    //1.每一行的数据都是那一行的第一个数字的倍数，应当能被这行的第一个数字整除；2.每一行的数据都有一个最大值，应当小于这个最大值
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
