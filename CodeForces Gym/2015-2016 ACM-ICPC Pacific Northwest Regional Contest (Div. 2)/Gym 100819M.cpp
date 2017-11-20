#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1005

string str[11];
int a[11];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        cin >> str[i] >> a[i];
    int cnt=0;
    for(int i=1; i<=100; i++)
    {
        int temp=i;
        bool flag=false;
        for(int j=1; j<=n; j++)
        {
            if(str[j]=="ADD")
                temp+=a[j];
            else if(str[j]=="SUBTRACT")
            {
                temp-=a[j];
                if(temp<0)
                {
                    flag=true;
                    break;
                }
            }
            else if(str[j]=="MULTIPLY")
                temp*=a[j];
            else
            {
                if(temp%a[j])
                {
                    flag=true;
                    break;
                }
                else
                    temp/=a[j];
            }
        }
        if(flag)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
