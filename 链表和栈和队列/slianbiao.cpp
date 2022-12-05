#include <iostream>
using namespace std;
//����ʹ��˫������ʵ�ֶ��к�ջ
template<class T>
struct QueueNode{             //˫�˶��б����ϻ���������˫������Ľṹ��
    T val;
    QueueNode<T>* last;
    QueueNode<T>* next;

    QueueNode(T data)
    {
        val=data;
    }

    QueueNode()
    {}
};

//˫�˶��е�ʵ��
template<class T>
class WQueue{
    public:
        QueueNode<T>* AddFromFront(T val)
        {
            QueueNode<T>* cur = new QueueNode<T> (val);    //���ַ�ʽ��ֱ�Ӵ�������ܷ���
            if (head==nullptr)
            {
                head=cur;
                tail=cur;
            } else {
                cur->next=head;     //����headֻ�����˵�ǰ��ָ��Ķ���
                head->last=cur;
                head=cur;           //head��tail Ҫ����ȫ��ָ���õ�˼��
            }
            return head;
        };

        QueueNode<T>* AddFromBack(T val)
        {
            QueueNode<T>* cur = new QueueNode<T> (val);    //���ַ�ʽ��ֱ�Ӵ�������ܷ���
            if (head==nullptr)
            {
                head=cur;
                tail=cur;
            } else {
                cur->next=tail;     //����headֻ�����˵�ǰ��ָ��Ķ���
                tail->last=cur;
                tail=cur;           //head��tail Ҫ����ȫ��ָ���õ�˼��
            }
            return tail;
        };

        QueueNode<T>* PopFromFront()
        {
            if (head==nullptr)
            {
                return nullptr;
            }
            QueueNode<T>* cur = head;    //������ָ��, ��Ҫ������ָ�����ָ����ڴ�����ܷ���
            if (head==tail)
            {
                head=nullptr;
                tail=nullptr;
                return nullptr;
            } else {
                head=head->next;
                cur->next=nullptr;
                head->last=nullptr;
                return head;
            }
        }

        QueueNode<T>* PopFromBack()
        {
            if (tail==nullptr)
            {
                return nullptr;
            }
            QueueNode<T>* cur = tail;    //������ָ��
            if (head==tail)
            {
                head=nullptr;
                tail=nullptr;
                return nullptr;
            } else {
                tail=tail->next;
                cur->next=nullptr;
                tail->last=nullptr;
                return tail;
            }
        }

        bool isEmpty()
        {
            return head==nullptr;
        }

    private:
        QueueNode<T> *head;      //����ָ�룬������ס���е��ײ���β��
        QueueNode<T> *tail;
};

//���Լ�����˫�˶��е�ģ���෽����ȥʵ��ջ�Ͷ���, �ɲο�class03-code03

int main(){
    // QueueNode<int> qq=QueueNode<int> (10);
    // cout<<qq.val;
    // QueueNode<char> pp=QueueNode<char> ('a');
    // cout<<pp.val;

    WQueue<int> wyl;              //wyl����һ��int�͵�˫�˶���
    QueueNode<int> *test, *res;
    wyl.AddFromFront(1);
    wyl.AddFromFront(3);
    wyl.AddFromBack(4);
    wyl.AddFromBack(8);
    test=wyl.PopFromFront();      //�������wyl����������Ĳ���
    cout<<test->val;
    res=wyl.PopFromBack();
    cout<<res->val;
    cout<<wyl.isEmpty();
}