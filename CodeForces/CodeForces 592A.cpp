#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char a[10][10];
    memset(a,0,sizeof(a));
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            cin >> a[i][j];
    int num1=100,num2=100;
    int flag;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            flag=1;
            if(a[i][j]=='W')
            {
                for(int k=i-1;k>=0;k--)
                {
                    if(a[k][j]!='.')
                        flag=0;
                }
                if(flag==1)
                    num1=min(i,num1);
            }
            flag=1;
            if(a[i][j]=='B')
            {
                for(int k=i+1;k<8;k++)
                {
                    if(a[k][j]!='.')
                        flag=0;
                }
                if(flag==1)
                    num2=min(8-i-1,num2);
            }
        }
    }
    if(num1<=num2)
        cout << 'A' << endl;
    else
        cout << 'B' << endl;
}
