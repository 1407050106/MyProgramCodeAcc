#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include <numeric>
#include <algorithm>
#include <memory>
#include <cmath>
#include <ctime>
using namespace std;

// ��Ŀ��
// ����һ����������arr������������X���ϵĵ�
// ����һ������K���������ӵĳ���
// �����������ѹ�м����㣿
// ��ʹ���ӱ�Ե����ס��Ҳ���ס
vector<int> a{1,2,3,4,7,13,16,17};  // eg:����Ϊ4����������ܸ�ס�����㣿
int aim=3;

class solution{
    public:
        // �û�������+����ָ�룬�����ˣ�O��N���㶨��
        // ����������룺ֻҪ�±겻Խ�磬���е���
        int findnum(vector<int> v, int len)
        {
            int L=0, R=0, edge=v.size();
            int res=1;
            while (L<edge)  // ע�⣡��
            {
                int count=0;
                while (R<edge && v[R]-v[L]<=len)
                {
                    R++;
                    count++;
                }
                res=max(res, count);
                L++;
            }
            return res;
        }
};

int main()
{
    solution st;
    int ans=st.findnum(a, aim);
    cout<<"ans= "<<ans<<endl;
}