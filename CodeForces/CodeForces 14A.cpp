#include <iostream>
using namespace std;

char pic[55][55];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> pic[i];
    int x1=0,x2=n-1,y1=0,y2=m-1;
    bool flag=false;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(pic[i][j]=='*')
            {
                x1=i;
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    flag=false;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<m; j++)
        {
            if(pic[i][j]=='*')
            {
                x2=i;
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    flag=false;
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(pic[i][j]=='*')
            {
                y1=j;
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    flag=false;
    for(int j=m-1; j>=0; j--)
    {
        for(int i=0; i<n; i++)
        {
            if(pic[i][j]=='*')
            {
                y2=j;
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    for(int i=x1; i<=x2; i++)
    {
        for(int j=y1; j<=y2; j++)
            cout << pic[i][j];
        cout << endl;
    }
    return 0;
}
