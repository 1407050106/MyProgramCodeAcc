#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int remvfloor(stack<int>& v);
void reversestack(stack<int>& v);

void reversestack(stack<int>& v)
{
    if (v.empty())
    {
        return;
    }
    int i = remvfloor(v);
    reversestack(v);
    v.push(i);
}

// �Ƴ�ջ��Ԫ�أ���ջ��ʣ��Ԫ�ؼ���ѹ��ȥ, ����ջ��Ԫ��
int remvfloor(stack<int>& v)
{
    int result = v.top();
    v.pop();
    if (v.empty())
    {
        return result;
    } else {
        int last=remvfloor(v);
        // ��ѹ��ջ
        v.push(result);
        // �ٷ���ֵ����һ��ʹ��
        return last;
    }
}

int main() {
    stack<int> test;
    test.push(1);
    test.push(2);
    test.push(3);

    reversestack(test);
    while (!test.empty())
    {
        cout<<test.top()<<" ";
        test.pop();
    }
}