#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int num[500];

int main()
{
    for(int i=1; i<500; i++)
        num[i]=i*(i-1)/2;
    int k;
    scanf("%d",&k);
    char ch='a';
    if(k==0)
    {
        puts("a");
        return 0;
    }
    while(k)
    {
        int pos=lower_bound(num,num+500,k)-num;
        //cout << pos << endl;
        if(num[pos]>k)
            pos--;
        for(int i=0; i<pos; i++)
            printf("%c",ch);
        k-=num[pos];
        ch++;
        //cout << k << endl;
    }
    puts("");
    return 0;
}
