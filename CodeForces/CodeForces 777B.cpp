#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

char str[MAXN];
int sher[MAXN],mor[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=1; i<=n; i++)
        sher[i]=str[i-1]-'0';
    scanf("%s",str);
    for(int i=1; i<=n; i++)
        mor[i]=str[i-1]-'0';
    sort(sher+1,sher+n+1);
    sort(mor+1,mor+n+1);
    int p1=1;
    int p2=1;
    while(p1<=n && p2<=n)
    {
        if(sher[p1]<=mor[p2])   //尽量少被敲，平局可接受
        {
            p1++;
            p2++;
        }
        else
            p2++;
    }
    int cnt1=n-p1+1;
    p1=1,p2=1;
    while(p1<=n && p2<=n)
    {
        if(sher[p1]<mor[p2])    //尽量多敲别人，多赢
        {
            p1++;
            p2++;
        }
        else
            p2++;
    }
    int cnt2=p1-1;
    printf("%d\n%d\n",cnt1,cnt2);
    //for(int i=0; i<n; i++)
    //    printf("%d",mor[i]);
    //printf("\n");
    return 0;
}
