#include <iostream>
#include <algorithm>
#define MAXN 100005
#define INF 1e9+7
using namespace std;

//ȷ����������ұ߽磨�㣩
void checkRange(int xy, int ab, int wh, double &left, double &right)
{
    if(ab==0)
    {
        if(xy<=0 || xy>=wh)  //�÷����ٶ�Ϊ�㣬�Ҹ÷����ڷ�Χ�ڣ��򲻻���������Χ
            right=left-1;
    }
    else if(ab>0)
    {
        left=max(left,-(double)xy/ab);  //����˵㣬��Ϊ�ٶȷ���Ϊ��������뷶Χ��ʱ������Ҫ�ڳ�ʼ����xyǰ�Ӹ�����
        right=min(right,(double)(wh-xy)/ab);    //���Ҷ˵�
    }
    else
    {
        left=max(left,(double)(wh-xy)/ab);  //����˵�
        right=min(right,-(double)xy/ab);    //���Ҷ˵㣬��Ϊ�ٶȷ���Ϊ�������뿪��Χ��ʱ������Ҫ�ڳ�ʼ����xyǰ�Ӹ�����
    }
}

struct MeteorStatus
{
    double x;   //λ������
    int status; //0��ʾ��߽�㣬1��ʾ�ұ߽��
    bool operator < (const MeteorStatus& a) const
    {
        if(x==a.x)
            return status>a.status; //��ĳһ��������ұ߽�����һ����߽��غϣ����ȴ����ұ߽磬�����ظ��������
        return x<a.x;
    }
} ms[MAXN*2];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int w,h,n,pt=0; //���ڼ������ṹ������ұ߽������
        cin >> w >> h >> n;
        for(int i=0; i<n; i++)
        {
            int x,y,a,b;    //X=x+at,Y=y+bt,0<X<w,0<Y<h,t>=0
            cin >> x >> y >> a >> b;
            double left=0,right=INF;    //�ұ߽��ʼֵ�趨Ϊint�����ֵ
            checkRange(x,a,w,left,right);   //ȷ��x�������������
            checkRange(y,b,h,left,right);   //ȷ��y�������������
            //�ۺϺ��γ�����������
            if(left<right)
            {
                ms[pt++]=(MeteorStatus){left,0};    //��¼��߽�
                ms[pt++]=(MeteorStatus){right,1};   //��¼�ұ߽�
            }
        }
        sort(ms,ms+pt); //���򣬴�����
        int cnt=0,ans=0;
        for(int i=0; i<pt; i++)
        {
            if(ms[i].status==0) //�������߽磬����+1�Ҹ��½��������Χ���������
            {
                cnt++;
                ans=max(ans,cnt);
            }
            else    //������ұ߽磬����-1
                cnt--;
        }
        cout << ans << endl;
    }
    return 0;
}
