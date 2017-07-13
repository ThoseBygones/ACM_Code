#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

int cnt;

void selection_sort(int a[],int n)
{
    int Min;
    for(int i=0; i<n; i++)
    {
        Min=i;
        for(int j=i; j<n; j++)
        {
            if(a[Min]>a[j])
                Min=j;
        }
        swap(a[Min],a[i]);
        if(Min!=i)
            cnt++;
    }
}

int main()
{
    int a[MAXN];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    cnt=0;
    selection_sort(a,n);
    for(int i=0; i<n-1; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    printf("%d\n",cnt);
    return 0;
}
