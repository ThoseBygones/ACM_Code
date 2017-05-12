#include <iostream>
using namespace std;

struct points
{
    int x;
    int y;
} p[3];

bool rightangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    int b=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
    int c=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
    if(a==0 || b==0 || c==0)
        return false;
    if(a+b==c || a+c==b || b+c==a)
        return true;
    return false;
}

int main()
{
    for(int i=0; i<3; i++)
        cin >> p[i].x >> p[i].y;
    if(rightangle(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y))
        cout << "RIGHT" << endl;
    else
    {
        bool flag;
        for(int i=0; i<3; i++)
        {
            flag=true;
            p[i].x++;
            if(rightangle(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y))
            {
                cout << "ALMOST" << endl;
                flag=false;
                break;
            }
            p[i].x--;
            p[i].x--;
            if(rightangle(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y))
            {
                cout << "ALMOST" << endl;
                flag=false;
                break;
            }
            p[i].x++;
            p[i].y++;
            if(rightangle(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y))
            {
                cout << "ALMOST" << endl;
                flag=false;
                break;
            }
            p[i].y--;
            p[i].y--;
            if(rightangle(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y))
            {
                cout << "ALMOST" << endl;
                flag=false;
                break;
            }
            p[i].y++;
        }
        if(flag)
            cout << "NEITHER" << endl;
    }
    return 0;
}
