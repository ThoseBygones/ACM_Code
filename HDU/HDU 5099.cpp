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

char s1[15];
char s2[15];

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        printf("Case %d: ",kase++);
        if(s1[0]<s2[0])
            printf("< ");
        else if(s1[0]==s2[0])
            printf("= ");
        else
            printf("> ");
        if(s1[1]==s2[1])
        {
            bool flag=true;
            for(int i=2; i<=5; i++)
            {
                if(s1[i]<s2[i])
                {
                    printf("<");
                    flag=false;
                    break;
                }
                if(s1[i]>s2[i])
                {
                    printf(">");
                    flag=false;
                    break;
                }
            }
            if(flag)
                printf("=");
        }
        else
        {
            bool flag=true;
            for(int i=2; i<=4; i++)
            {
                if(s1[i]<s2[i])
                {
                    printf("<");
                    flag=false;
                    break;
                }
                if(s1[i]>s2[i])
                {
                    printf(">");
                    flag=false;
                    break;
                }
            }
            if(flag)
                printf("=");
        }
        puts("");
    }
    return 0;
}
