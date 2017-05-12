#include <iostream>
#include <cstring>
using namespace std;

char mat[12][12];
int n;

int main()
{
    int t;
    cin >> t;
    for(int kase=1; kase<=t; kase++)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> mat[i];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]=='.')
                {
                    for(char c='A'; c<='Z'; c++)
                    {
                        bool fillIn=true;
                        if(j-1>=0 && mat[i][j-1]==c)
                            fillIn=false;
                        if(j+1<n && mat[i][j+1]==c)
                            fillIn=false;
                        if(i-1>=0 && mat[i-1][j]==c)
                            fillIn=false;
                        if(i+1<n && mat[i+1][j]==c)
                            fillIn=false;
                        if(fillIn)
                        {
                            mat[i][j]=c;
                            break;
                        }
                    }
                }
            }
        }
        cout << "Case " << kase << ":" << endl;
        for(int i=0; i<n; i++)
            cout << mat[i] << endl;
    }
    return 0;
}
