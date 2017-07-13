#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

void print(int a[],int n)
{
    for(int i=1; i<n; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
}

void insertion_sort(int a[],int n)
{
    int temp;
    for(int i=2; i<=n; i++)
    {
        temp=a[i];
        int j=i-1;
        while(j>=1 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        print(a,n);
    }
}

int main()
{
    int n;
    int a[MAXN];
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    print(a,n);
    insertion_sort(a,n);
    return 0;
}
