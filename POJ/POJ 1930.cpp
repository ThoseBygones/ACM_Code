#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f

/*（。为小数点）
设一个无限循环小数0.abcdefg...
设不循环部分长为k，循环部分长为c
设这个小数能化为a/b
10^(k+c)*a/b = abcdefg。...
10^c*a/b = abcd。efg...
两式相减得：10^(k+c)*a/b-10^c*a/b = abcdefg-abcd
得到：a / b = (abcdefg-abcd) / (10^c*(10^k-1))
约分a/b得到最简即可
*/

char num[50];

int main()
{
    while(~scanf("%s",num))
    {
        if(strcmp(num,"0")==0)
            break;
        int sum=0;
        int cnt=0;
        for(int i=2; num[i]!='.'; i++)
        {
            sum=sum*10+num[i]-'0';
            cnt++;
        }
        int temp=sum;
        int k=1;    //k为不循环数位的值
        int mina=INF,minb=INF;
        for(int i=1; i<=cnt; i++)
        {
            temp/=10;
            k*=10;
            int a=sum-temp;
            int b=(int)pow(10,cnt-i)*(k-1);
            int c=__gcd(a,b);
            if(b/c<minb)
            {
                mina=a/c;
                minb=b/c;
            }
        }
        printf("%d/%d\n",mina,minb);
    }
    return 0;
}
