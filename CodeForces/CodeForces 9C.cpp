#include<iostream>
using namespace std;

int n,cnt;

void decimal(int x)
{
    if(x>n)
        return ;
    cnt++;
    decimal(10*x);
    decimal(10*x+1);
}

int main()
{
    while(cin >> n)
    {
        cnt=0;
        decimal(1);
        cout << cnt << endl;
    }
    return 0;
}
