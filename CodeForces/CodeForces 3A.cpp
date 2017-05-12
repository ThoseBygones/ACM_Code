#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

char x1[2],x2[2],rec[100][5];
int ya,yb;

int main()
{
    int delx,dely,sum,i,j;
    cin >> x1[0];
    x1[1]='\0';
    cin >> ya;
    cin >> x2[0];
    x2[1]='\0';
    cin >> yb;
    delx=x1[0]-x2[0];
    dely=ya-yb;
    j=0;
    if(delx>=0)
    {
        for(i=delx; i>0; i--,j++)
            rec[j][0]='L';
    }
    else
    {
        for(i=delx; i<0; i++,j++)
            rec[j][0]='R';
    }
    j=0;
    if(dely>=0)
    {
        for(i=dely; i>0; i--,j++)
        {
            if(rec[j][0]=='\0')
                rec[j][0]='D';
            else
                rec[j][1]='D';
        }
    }
    else
    {
        for(i=dely; i<0; i++,j++)
        {
            if(rec[j][0]=='\0')
                rec[j][0]='U';
            else
                rec[j][1]='U';
        }
    }
    sum=max(abs(delx),abs(dely));
    cout << sum << endl;
    for(i=0; i<sum; i++)
        cout << rec[i] << endl;
    return 0;
}
