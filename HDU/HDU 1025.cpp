#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 500005

int a[MAXN];
int b[MAXN];

int biSearch(int val,int left,int right)
{
    while(left<=right)
    {
        int mid=(left+right)>>1;
        if(val>=b[mid])
            left=mid+1;
        else
            right=mid-1;
    }
    return left;
}

int main()
{
    int t;
    int kase=1;
    while(~scanf("%d",&t))
    {
        for(int i=1; i<=t; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        b[1]=a[1];
        int len=1;
        int p=0;
        for(int i=2; i<=t; i++)
        {
            if(a[i]>b[len]) //比b数组中的最后一个数字还大，直接在数组最后追加
                b[++len]=a[i];
            else
            {
                p=biSearch(a[i],1,len);
                b[p]=a[i];
            }
        }
        if(len==1)
            printf("Case %d:\nMy king, at most 1 road can be built.\n",kase++);
        else
            printf("Case %d:\nMy king, at most %d roads can be built.\n",kase++,len);
        puts("");
    }
    return 0;
}
