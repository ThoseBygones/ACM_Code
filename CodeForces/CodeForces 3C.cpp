//CodeForces 3C -- �����ǿӵ�һ����
//�ж�illegal��Ҫ�ǳ�ע�⣬�кܶ���illegal����
//�жϸ�����������ȼ���illegal > the first player won = the second player won > draw > first = second
#include <iostream>
using namespace std;

char board[3][3];

bool check(char mark)   //�жϻ�ʤ�ļ������
{
    for(int i=0; i<3; i++)
    {
        if(board[i][0]==mark && board[i][1]==mark && board[i][2]==mark) //ĳ����������ͬ��
            return true;
    }
    for(int j=0; j<3; j++)
    {
        if(board[0][j]==mark && board[1][j]==mark && board[2][j]==mark) //ĳ����������ͬ��
            return true;
    }
    if((board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) || (board[2][0]==mark && board[1][1]==mark && board[0][2]==mark))  //���Խ��߻򸱶Խ�����������ͬ��
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
            if(board[i][j]=='X')    //��¼X������
                cnt1++;
            if(board[i][j]=='0')    //��¼0������
                cnt2++;
        }
    }
    //cout << cnt1 << " " << cnt2 << endl;
    /*�ؼ���һ�����жϷǷ���ֵ������X�������ϵ���������0���������ϣ�0��������Xsecond�ࣻX�Ѿ���ʤ�ˣ���0��������Ȼ��X������һ���ࣨ�������ѻ�ʤ�����ֻ���������һ���壩��0�Ѿ���ʤ�ˣ���X��������Ȼ����0��1�������ѻ�ʤ�����ֻ���������һ���壩��*/
    if(cnt1-cnt2>1 || cnt2>cnt1 || (check('X') && check('0')) || (check('X') && cnt1==cnt2) || (check('0') && cnt1>cnt2))
    {
        cout << "illegal" << endl;
        return 0;
    }
    if(check('X'))  //���ֻ�ʤ
    {
        cout << "the first player won" << endl;
        return 0;
    }
    if(check('0'))  //���ֻ�ʤ
    {
        cout << "the second player won" << endl;
        return 0;
    }
    if(cnt1+cnt2==9)    //ƽ��
    {
        cout << "draw" << endl;
        return 0;
    }
    if(cnt1>cnt2)   //��һ���ֵ�����
    {
        cout << "second" << endl;
    }
    else    //��һ���ֵ�����
    {
        cout << "first" << endl;
    }
    return 0;
}
