#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

int a[MAXN];
int n;

int divide(int p,int r)
{
    int temp=a[r];
    int i=p-1;
    for(int j=p; j<r; j++)
    {
        if(a[j]<=temp)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int q=divide(0,n-1);
    for(int i=0; i<n; i++)
    {
        if(i)
            printf(" ");
        if(i==q)
            printf("[");
        printf("%d",a[i]);
        if(i==q)
            printf("]");
    }
    printf("\n");
    return 0;
}
