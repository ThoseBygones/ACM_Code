#include <iostream>
using namespace std;

int hol[360];

int main()
{
    int n,k,c,temp;
    cin >> n >> k >> c;
    for(int i=0; i<c; i++)
    {
        cin >> temp;
        hol[temp]=1;
    }
    int cnt=0;
    int day=1;
    int p=0;
    while(day<=n)
    {
        if(hol[day])
        {
            p=day;
            cnt++;
        }
        else if(day==p+k)
        {
            cnt++;
            p=day;
        }
        day++;
    }
    cout << cnt << endl;
    return 0;
}
