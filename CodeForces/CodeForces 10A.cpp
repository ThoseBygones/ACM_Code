#include <iostream>
using namespace std;

int n,p1,p2,p3,t1,t2;
int l[105],r[105];

int main()
{
    while(cin >> n >> p1 >> p2 >> p3 >> t1 >> t2)
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin >> l[i] >> r[i];
        }
        for(int i=0; i<n; i++)
        {
            sum+=p1*(r[i]-l[i]);
        }
        for(int i=1; i<n; i++)
        {
            int t=l[i]-r[i-1];
            if(t>t1+t2)
                sum+=p1*t1+p2*t2+p3*(t-t1-t2);
            else if(t>t1)
                sum+=p1*t1+p2*(t-t1);
            else
                sum+=p1*t;
        }
        cout << sum << endl;
    }
    return 0;
}
