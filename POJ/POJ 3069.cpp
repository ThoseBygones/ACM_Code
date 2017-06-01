#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int a[MAXN];

int main()
{
    int r,n;
    while(~scanf("%d%d",&r,&n))
    {
        if(r==-1 && n==-1)
            break;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int p=0;
        int cnt=0;
        while(p<n)
        {
            int left=a[p++];
            while(p<n && a[p]-left<=r)
                p++;
            int mid=a[p-1];
            while(p<n && a[p]-mid<=r)
                p++;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
