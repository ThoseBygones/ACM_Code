#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num[12];
int n;

bool check(int x,int y)
{
    if(x>98765)
        return false;
    memset(num,0,sizeof(num));
    if(y<10000)
        num[0]=1;
    while(x)
    {
        num[x%10]=1;
        x/=10;
    }
    while(y)
    {
        num[y%10]=1;
        y/=10;
    }
    int cnt=0;
    for(int i=0; i<10; i++)
    {
        if(num[i])
            cnt++;
    }
    if(cnt==10)
        return true;
    return false;
}

int main()
{
    bool flag;
    int kase=0;
    while(cin >> n)
    {
        if(n==0)
            break;
        if(kase++)
            cout << endl;
        flag=false;
        for(int i=1234; i<50000; i++)
        {
            int m=n*i;
            if(check(m,i))
            {
                flag=true;
                printf("%05d / %05d = %d\n",m,i,n);
            }
        }
        if(!flag)
            cout << "There are no solutions for " << n << "." << endl;
    }
    return 0;
}
