#include <iostream>
using namespace std;

void recordfolder(int N);
void process(int i, int N, bool down);

void recordfolder(int N)
{
    process(1,N,true);
}

// ϣ����һ�����������������ӡÿһ���ڵ�İ�͹ֵ,�������Ϊ�и߶�ֵ�������Ѿ����ɹ̶��õ�,�����!
// ��ǰ������һ���ڵ㣬�Ժ�������ģ�
// ����ڵ��ڵ�i�㣬һ����N�㣬N�̶������
// ����ڵ�����ǰ��Ļ���down = T
// ����ڵ������͹�Ļ���down = F
void process(int i, int N, bool down)
{
    // �ݹ����ֹ������
    if (i>N) return;
    process(i+1, N, true);  // ȥ�ݹ���һ�������
    string s = down?"a":"t";
    cout<<s<<" ";
    process(i+1, N, false);  // ȥ�ݹ���һ����Һ���
    // �������⿼��Զ������ĵݹ����������,������ʽ�������!
}

int main() {
    int N = 2;
    recordfolder(N);
}