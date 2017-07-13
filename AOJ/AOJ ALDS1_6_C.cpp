#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100010
#define INF 0x3f3f3f3f

struct Card
{
    char suit;
    int value;
};

Card L[MAXN/2],R[MAXN/2];
int n;

void conquer(Card a[],int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0; i<n1; i++)
        L[i]=a[left+i];
    for(int i=0; i<n2; i++)
        R[i]=a[mid+i];
    L[n1].value=R[n2].value=INF;
    int p,q;
    p=q=0;
    for(int i=left; i<right; i++)
    {
        if(L[p].value<=R[q].value)
            a[i]=L[p++];
        else
            a[i]=R[q++];
    }
}

void mergesort(Card a[],int left,int right)
{
    int mid;
    if(left+1<right)
    {
        mid=(left+right)>>1;
        mergesort(a,left,mid);
        mergesort(a,mid,right);
        conquer(a,left,mid,right);
    }
}

int divide(Card a[],int p,int r)
{
    Card temp;
    temp=a[r];
    int i=p-1;
    for(int j=p; j<r; j++)
    {
        if(a[j].value<=temp.value)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quicksort(Card a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=divide(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int main()
{
    Card a[MAXN],b[MAXN];
    char s[5];
    bool stable=true;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int val;
        scanf("%s %d",s,&val);
        a[i].suit=b[i].suit=s[0];
        a[i].value=b[i].value=val;
    }
    mergesort(a,0,n);
    quicksort(b,0,n-1);
    for(int i=0; i<n; i++)
    {
        if(a[i].suit!=b[i].suit)
        {
            stable=false;
            break;
        }
    }
    if(stable)
        puts("Stable");
    else
        puts("Not stable");
    for(int i=0; i<n; i++)
        printf("%c %d\n",b[i].suit,b[i].value);
    return 0;
}
