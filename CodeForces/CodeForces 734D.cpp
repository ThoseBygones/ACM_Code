#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Chess
{
    int x;
    int y;
    char type;
} chess[500005];

int n,xx,yy;

bool judge1(int i,int x)
{
    bool check=false;
    for(int j=0; j<n; j++)
    {
        if(j==i)
            continue;
        if(chess[j].x>min(x,xx) && chess[j].x<max(x,xx) && chess[j].y==yy)
        {
            check=false;
            break;
        }
        else
            check=true;
    }
    return check;
}

bool judge2(int i,int y)
{
    bool check=true;
    for(int j=0; j<n; j++)
    {
        if(j==i)
            continue;
        if(chess[j].y>min(y,yy) && chess[j].y<max(y,yy) && chess[j].x==xx)
        {
            check=false;
            break;
        }
        else
            check=true;
    }
    return check;
}

bool judge3(int i,int x,int y)
{
    bool check=true;
    for(int j=0; j<n; j++)
    {
        if(j==i)
            continue;
        if(chess[j].x>min(x,xx) && chess[j].x<max(x,xx) && chess[j].y>min(y,yy) && chess[j].y<max(y,yy) && abs(chess[j].x-xx)==abs(chess[j].y-yy))
        {
            check=false;
            break;
        }
        else
            check=true;
    }
    return check;
}

int main()
{
    cin >> n >> xx >> yy;
    for(int i=0; i<n; i++)
        cin >> chess[i].type >> chess[i].x >> chess[i].y;
    for(int i=0; i<n; i++)
    {
        if(chess[i].type=='R')
        {
            if(chess[i].x==xx)
            {
                if(judge2(i,chess[i].y))
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
            if(chess[i].y==yy)
            {
                if(judge1(i,chess[i].x))
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        else if(chess[i].type=='B')
        {
            if(abs(chess[i].x-xx)==abs(chess[i].y-yy))
            {
                if(judge3(i,chess[i].x,chess[i].y))
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        else if(chess[i].type=='Q')
        {
            if(chess[i].x==xx)
            {
                if(judge2(i,chess[i].y))
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
            if(chess[i].y==yy)
            {
                if(judge1(i,chess[i].x))
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
            if(abs(chess[i].x-xx)==abs(chess[i].y-yy))
            {
                if(judge3(i,chess[i].x,chess[i].y))
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

/*
3
1 1
R 1 5
B 1 3
R 5 5
3
1 1
R 1 5
B 1 3
R 5 5
*/
