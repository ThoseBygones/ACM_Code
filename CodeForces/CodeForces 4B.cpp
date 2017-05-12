#include <iostream>
#define MAXN 35
using namespace std;

int minDay[MAXN],maxDay[MAXN];
int minsum,maxsum;

int main()
{
    int d,sumTime;
    cin >> d >> sumTime;
    for(int i=1; i<=d; i++)
    {
        cin >> minDay[i] >> maxDay[i];
        minsum+=minDay[i];
        maxsum+=maxDay[i];
    }
    if(sumTime>maxsum || sumTime<minsum)
    {
        cout << "NO" << endl;
        return 0;
    }
    int extra=maxsum-sumTime;
    for(int i=1; i<=d && extra; i++)
    {
        if(maxDay[i]-minDay[i]>=extra)
        {
            maxDay[i]-=extra;
            extra=0;
        }
        else
        {
            extra-=(maxDay[i]-minDay[i]);
            maxDay[i]=minDay[i];
        }
    }
    cout << "YES" << endl;
    for(int i=1; i<d; i++)
        cout << maxDay[i] << " ";
    cout << maxDay[d] << endl;
    return 0;
}
