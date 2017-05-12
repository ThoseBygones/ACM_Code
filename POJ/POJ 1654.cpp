#include<iostream>
#include<cstring>
using namespace std;

int dx[10]={0,-1,0,1,-1,0,1,-1,0,1};
int dy[10]={0,-1,-1,-1,0,0,0,1,1,1};
char str[1000010];
long long int area;
int px1,py1,px2,py2;

int main()
{
    int t;
    while(cin >> t)
    {
        while(t--)
        {
            cin >> str;
            int len=strlen(str);
            px1=px2=py1=py2=0;
            area=0;
            for(int i=0; i<len; i++)
            {
                px2=px1+dx[str[i]-'0'];
                py2=py1+dy[str[i]-'0'];
                area+=px2*py1-px1*py2;
                px1=px2;
                py1=py2;
            }
            if(area<0)
                area=-area;
            if(area%2==0)
                cout << area/2 << endl;
            else
                cout << area/2 << ".5" << endl;
        }
    }
    return 0;
}
