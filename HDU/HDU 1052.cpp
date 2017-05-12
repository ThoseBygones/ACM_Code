#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int tian[1005],king[1005];

int main()
{
    int n,sum;
    while(~scanf("%d",&n),n)
    {
        int tmax,tmin,kmax,kmin;
        for(int i=0; i<n; i++)
            cin >> tian[i];
        for(int i=0; i<n; i++)
            cin >> king[i];
        sort(tian,tian+n);
        sort(king,king+n);
        sum=0;
        tmax=kmax=n-1;
        tmin=kmin=0;
        while(tmax>=tmin && kmax>=kmin)
            if(tian[tmax]>king[kmax])
            {
                sum+=200;
                tmax--;
                kmax--;
            }
            else if(tian[tmax]<king[kmax])
            {
                sum-=200;
                tmin++;
                kmax--;
            }
            else
            {
                if(tian[tmin]>king[kmin])
                {
                    sum+=200;
                    tmin++;
                    kmin++;
                }
                else if(tian[tmin]<king[kmin])
                {
                    sum-=200;
                    tmin++;
                    kmax--;
                }
                else
                {
                    if(tian[tmin]<king[kmax])
                        sum-=200;
                    tmin++;
                    kmax--;
                }
            }
        cout << sum << endl;
    }
    return 0;
}
