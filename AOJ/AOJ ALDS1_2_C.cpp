#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 40

struct Card
{
    char suit;
    char num;
} c1[MAXN],c2[MAXN];

void bubble_sort(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=n-1; j>i; j--)
        {
            if(c1[j].num<c1[j-1].num)
                swap(c1[j],c1[j-1]);
        }
    }
}

void selection_sort(int n)
{
    for(int i=0; i<n; i++)
    {
        int Min=i;
        for(int j=i; j<n; j++)
        {
            if(c2[j].num<c2[Min].num)
                Min=j;
        }
        swap(c2[Min],c2[i]);
    }
}

bool checkStability(int n)
{
    for(int i=0; i<n; i++)
    {
        if(c1[i].suit!=c2[i].suit)
            return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        char temp[5];
        scanf("%s",temp);
        c1[i].suit=c2[i].suit=temp[0];
        c1[i].num=c2[i].num=temp[1];
    }
    bubble_sort(n);
    selection_sort(n);
    for(int i=0; i<n-1; i++)
        printf("%c%c ",c1[i].suit,c1[i].num);
    printf("%c%c\n",c1[n-1].suit,c1[n-1].num);
    puts("Stable");
    for(int i=0; i<n-1; i++)
        printf("%c%c ",c2[i].suit,c2[i].num);
    printf("%c%c\n",c2[n-1].suit,c2[n-1].num);
    if(checkStability(n))
        puts("Stable");
    else
        puts("Not stable");
    return 0;
}
