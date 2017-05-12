#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int best(double a,double b)
{
    int pile=1+(int)(2*(b-1)/sqrt(3.0));
    double es=a-(int)a;
    //cout << es << endl;
    int ans=0;
    if(es<0.5)
    {
        if(pile%2==0)
            ans=pile/2*(2*(int)a-1);
        else
            ans=(pile-1)/2*(2*(int)a-1)+(int)a;
    }
    else
        ans=pile*(int)a;
    return ans;
}

int main()
{
    double a,b;
    while(cin >> a >> b)
    {
        if(a<1 || b<1)
        {
            cout << "0 grid" << endl;
            continue;
        }
        int mmax=(int)a*(int)b;
        //cout << best(a,b) << " " << best(b,a) << " " << mmax << endl;
        int ans=max(best(a,b),best(b,a));
        if(mmax>=ans)
            cout << mmax << " grid" << endl;
        else
            cout << ans << " skew" << endl;
    }
    return 0;
}
