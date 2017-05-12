#include<iostream>
#include<cmath>
using namespace std;

int s[105];

int main()
{
    int n,temp;
    double vb,vs,x,y;
    while(cin >> n >> vb >> vs)
    {
        double tmin=1e10;
        for(int i=0; i<n; i++)
            cin >> s[i];
        cin >> x >> y;
        for(int i=1; i<n; i++)
        {
            double t=sqrt((s[i]-x)*(s[i]-x)+y*y)/vs+s[i]/vb;
            if(t<=tmin)
            {
                tmin=t;
                temp=i;
            }
        }
        cout << temp+1 << endl;
    }
    return 0;
}
