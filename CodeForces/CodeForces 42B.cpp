#include <iostream>
using namespace std;

int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int wrx[2],wry[2],wkx,wky,bkx,bky;
int vis[10][10];
char s[5];

bool inMap(int x,int y)
{
    if(x>0 && x<=8 && y>0 && y<=8)
        return true;
    return false;
}

int main()
{
    for(int i=0; i<2; i++)
    {
        cin >> s;
        wrx[i]=s[0]-'a'+1;
        wry[i]=s[1]-'0';
    }
    cin >> s;
    wkx=s[0]-'a'+1;
    wky=s[1]-'0';
    cin >> s;
    bkx=s[0]-'a'+1;
    bky=s[1]-'0';
    for(int j=0; j<2; j++)
    {
        for(int i=0; i<4; i++)
        {
            int nx=wrx[j]+dx[i];
            int ny=wry[j]+dy[i];
            while(inMap(nx,ny) && (nx!=wkx || ny!=wky))
            {
                vis[nx][ny]=1;
                nx+=dx[i];
                ny+=dy[i];
            }
        }
    }
    for(int i=-1; i<=1; i++)
    {
        for(int j=-1; j<=1; j++)
        {
            if(inMap(wkx+i,wky+j))
                vis[wkx+i][wky+j]=1;
        }
    }
    for(int i=-1; i<=1; i++)
    {
        for(int j=-1; j<=1; j++)
        {
            if(inMap(bkx+i,bky+j) && !vis[bkx+i][bky+j])
            {
                cout << "OTHER" << endl;
                return 0;
            }
        }
    }
    cout << "CHECKMATE" << endl;
    return 0;
}
