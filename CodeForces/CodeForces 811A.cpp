#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    //bool flag=true;
    int cnt=1;
    while(true)
    {
        if(a>=cnt)
            a-=cnt;
        else
        {
            //flag=false;
            puts("Vladik");
            return 0;
        }
        cnt++;
        if(b>=cnt)
            b-=cnt;
        else
        {
            puts("Valera");
            return 0;
        }
        cnt++;
    }
    return 0;
}
