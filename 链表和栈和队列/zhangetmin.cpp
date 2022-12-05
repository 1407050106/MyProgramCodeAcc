#include <iostream>
#include <stack>
using namespace std;

//������ʵ��ջ
// template<class T>
// struct Node{
//     T val;
//     Node<T>* pre;
//     Node<T>* next;

//     Node(T value)
//     {
//         val = value;
//     }
// };

// template<class T>
// class zhanw{
//     public:
//         Node<T>* push(T target)
//         {
//             Node<T>* cur = new Node<T> (target);
//             if(head==nullptr)
//             {
//                 head=cur;
//                 tail=cur;
//             } else {
//                 cur->next=head;
//                 head->pre=cur;
//                 head=cur;
//             }
//             return head;
//         }

//         Node<T>* pop()
//         {
//             if (head==nullptr)
//             {
//                 return nullptr;
//             }
//             Node<T>* cur = head;
//             if (head==tail)
//             {
//                 head=nullptr;
//                 tail=nullptr;
//                 return nullptr;
//             } else {
//                 head=head->next;
//                 cur->next=nullptr;
//                 head->pre=nullptr;
//                 return head;
//             }
//         }

//         Node<T>* top(){
//             if (head==nullptr)
//             {
//                 return nullptr;
//             }
//             return head;
//         }

//         T GetMin() {
            
//         }

//     private:
//         Node<T>* head;
//         Node<T>* tail;
// };

//ʵ�ֻ�ȡջ����Сֵ-class03code05
class MyStack{
    public:
        MyStack()
        {
            stackData = new stack<int> ();
            stackMin = new stack<int> ();
        }

        void push(int aim)  //��Ϊ��ͬ���ģ������ж�����һ������, ����ٲ�����һ��
        { 
            if (stackMin->empty())
            {
                stackMin->push(aim);
            } else if (aim<getmin()) {
                stackMin->push(aim);
            } else {
                stackMin->push(getmin());
            }
            stackData->push(aim);
        }

        void pop()
        {
            if (stackData->empty())
            {
                throw runtime_error("No Value!\n");
            }
            stackMin->pop();
            stackData->pop();
        }

        int getmin()
        {
            if (stackMin->empty())
            {
                throw runtime_error("No Value!\n");
            }
            return stackMin->top();
        }
        
    private:
        stack<int>* stackData;
        stack<int>* stackMin;
};


int main() {
    // zhanw<char> super;
    // Node<char>* star; 
    // super.push('a'); 
    // super.push('b'); 
    // super.push('c'); 
    // super.pop();
    // star=super.top();
    // cout<<star->val<<endl;

    //����ջ��ȡ��Сֵ
    MyStack mystack;
    mystack.push(1);
    mystack.push(2);
    int a = mystack.getmin();
    cout<<"a="<<a<<endl;
    mystack.pop();
    int b = mystack.getmin();
    cout<<"b="<<b<<endl;
}