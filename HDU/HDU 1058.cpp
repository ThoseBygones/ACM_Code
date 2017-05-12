#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 6005

int hm[MAXN];
int cnt1,cnt2,cnt3,cnt4;

int Min(int a,int b,int c,int d)
{
    int t;
    t=a;
    t=min(t,b);
    t=min(t,c);
    t=min(t,d);
    if(a==t)
        cnt1++;
    if(b==t)
        cnt2++;
    if(c==t)
        cnt3++;
    if(d==t)
        cnt4++;
    return t;
}

int main()
{
    hm[1]=1;
    cnt1=cnt2=cnt3=cnt4=1;
    for(int i=2; i<=5842; i++)
        hm[i]=Min(2*hm[cnt1],3*hm[cnt2],5*hm[cnt3],7*hm[cnt4]);
    int n;
    while(~scanf("%d",&n),n)
    {
        if(n%10==1 && n%100!=11)
            printf("The %dst humble number is %d.\n",n,hm[n]);
        else if(n%10==2 && n%100!=12)
            printf("The %dnd humble number is %d.\n",n,hm[n]);
        else if(n%10==3 && n%100!=13)
            printf("The %drd humble number is %d.\n",n,hm[n]);
        else
            printf("The %dth humble number is %d.\n",n,hm[n]);
    }
    return 0;
}
