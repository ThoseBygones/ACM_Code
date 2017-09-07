#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f
#define PII pair
#define MP make_pair
#define LL long long
#define PB push_back
#define MOD 1000000007

int a[15];
char v[15]= {'0','p','q','r','u','v','w','x','y','z'};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1; i<=10; i++)
            scanf("%d",&a[i]);
        int cnt=0;
        for(int i=1; i<=10; i++)
        {
            if(a[i]==0)
                continue;
            if(cnt==0 && i!=10)
            {
                if(a[i]==1)
                    printf("%c",v[i]);
                else if(a[i]==-1)
                    printf("-%c",v[i]);
                else
                    printf("%d%c",a[i],v[i]);
            }
            else if(i==10)
            {
                if(cnt==0)
                {
                    printf("%d",a[i]);
                }
                else
                {
                    if(a[i]>0)
                        printf("+%d",a[i]);
                    else
                        printf("%d",a[i]);
                }
            }
            else if(cnt!=0)
            {
                if(a[i]>0)
                {
                    if(a[i]==1)
                        printf("+%c",v[i]);
                    else
                        printf("+%d%c",a[i],v[i]);
                }
                else
                {
                    if(a[i]==-1)
                        printf("-%c",v[i]);
                    else
                        printf("%d%c",a[i],v[i]);
                }
            }
            cnt++;
        }
        if(cnt==0)
            printf("0");
        puts("");
    }
    return 0;
}
