#include <iostream>
using namespace std;

char board[10][10];

int main()
{
    for(int i=0; i<8; i++)
        cin >> board[i];
    int sum=0;
    for(int i=0; i<8; i++)
    {
        bool allBlack = true;
        for(int j=0; j<8; j++)
        {
            if(board[i][j]=='W')
            {
                allBlack=false;
                break;
            }
        }
        if(allBlack)
            sum++;
    }
    for(int i=0; i<8; i++)
    {
        bool allBlack = true;
        for(int j=0; j<8; j++)
        {
            if(board[j][i]=='W')
            {
                allBlack=false;
                break;
            }
        }
        if(allBlack)
            sum++;
    }
    if(sum==16)
        sum=8;
    cout << sum << endl;
    return 0;
}
