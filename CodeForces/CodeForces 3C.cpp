//CodeForces 3C -- 满满是坑的一道题
//判断illegal需要非常注意，有很多种illegal可能
//判断各种情况的优先级：illegal > the first player won = the second player won > draw > first = second
#include <iostream>
using namespace std;

char board[3][3];

bool check(char mark)   //判断获胜的几种情况
{
    for(int i=0; i<3; i++)
    {
        if(board[i][0]==mark && board[i][1]==mark && board[i][2]==mark) //某行有三个相同的
            return true;
    }
    for(int j=0; j<3; j++)
    {
        if(board[0][j]==mark && board[1][j]==mark && board[2][j]==mark) //某列有三个相同的
            return true;
    }
    if((board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) || (board[2][0]==mark && board[1][1]==mark && board[0][2]==mark))  //主对角线或副对角线有三个相同的
        return true;
    return false;
}

int main()
{
    int cnt1=0,cnt2=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> board[i][j];
            if(board[i][j]=='X')    //记录X的数量
                cnt1++;
            if(board[i][j]=='0')    //记录0的数量
                cnt2++;
        }
    }
    //cout << cnt1 << " " << cnt2 << endl;
    /*关键的一步，判断非法格局的情况：X在棋盘上的数量多于0两个及以上；0的数量比Xsecond多；X已经获胜了，但0的数量竟然跟X的数量一样多（即先手已获胜，后手还接着下了一步棋）；0已经获胜了，但X的数量竟然还比0多1（后手已获胜，先手还接着下了一步棋）。*/
    if(cnt1-cnt2>1 || cnt2>cnt1 || (check('X') && check('0')) || (check('X') && cnt1==cnt2) || (check('0') && cnt1>cnt2))
    {
        cout << "illegal" << endl;
        return 0;
    }
    if(check('X'))  //先手获胜
    {
        cout << "the first player won" << endl;
        return 0;
    }
    if(check('0'))  //后手获胜
    {
        cout << "the second player won" << endl;
        return 0;
    }
    if(cnt1+cnt2==9)    //平局
    {
        cout << "draw" << endl;
        return 0;
    }
    if(cnt1>cnt2)   //下一步轮到后手
    {
        cout << "second" << endl;
    }
    else    //下一步轮到先手
    {
        cout << "first" << endl;
    }
    return 0;
}
