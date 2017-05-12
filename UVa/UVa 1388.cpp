#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        double avg1=10000.00/(m+n);
        double avg2=10000.00/n;
        double dis1=avg1;
        double dis2=avg2;
        double sum=0.0;
        for(int i=1; i<n; i++)
        {
            while(dis1<=dis2)
                dis1+=avg1;
            sum+=min(dis1-dis2,dis2-dis1+avg1);
            dis2+=avg2;
        }
        cout << fixed << setprecision(4) << sum << endl;
    }
    return 0;
}
