#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <numeric>
#include <unistd.h>
#include <cstring>
#include <climits>
#include <memory>
#include <queue>
#include <thread>
using namespace std;

// ��дһ�����ü�������
class countobj
{
    public:
        explicit countobj():count(1) {}

        void addcount()
        {
            ++count;
        }

        long deccount()
        {
            return --count;
        }

        long get() const
        {
            return count;
        }
    private:
        long count;
};

template<class T>
class mysmartptr{
    public:
        explicit mysmartptr(T* ptr=nullptr):myptr(ptr)
        {
            //if (!myptr) myptr = new T;  //?
            if (myptr)
            {
                smartptr_count = new countobj();
            }
        }

        ~ mysmartptr()
        {
            if (myptr && !smartptr_count->deccount())
            {
                delete myptr;
                delete smartptr_count;
            }
        }

        long getcount()
        {
            if (myptr)
            {
                return smartptr_count->get();
            } else {
                return 0;
            }
            
        }

//�������캯��
        mysmartptr(const mysmartptr& other)  // ע�⣡
        {
            this->myptr = other.myptr;
            if (myptr) // �����жϣ�����еĻ�(û�о���nullptr��Ҳû��)
            {
                other.smartptr_count->addcount();
                this->smartptr_count = other.smartptr_count; //ֻҪ����ĳ�Ա�������������У���Ա��������ν
            }
        }
// //ģ�忽�����캯��
//         template<typename U>
//         mysmartptr(const mysmartptr<U>& other)
//         {
//             myptr = other.myptr;
//             if (myptr)
//             {
//                 other.smartptr_count->addcount();
//                 smartptr_count = other.smartptr_count;
//             }
//         }
// //�ƶ����캯��
//         template<typename U>
//         mysmartptr(const mysmartptr<U>&& other)
//         {
//             myptr = other.myptr;
//             if (myptr)
//             {
//                 smartptr_count = other.smartptr_count;
//                 other.myptr=nullptr;
//             }
//         }

        mysmartptr& operator=(const mysmartptr& other)
        {
            // if (!(&other)) 
            // {
            //     return nullptr;
            // }
            this->myptr = other.myptr;
            other.smartptr_count->addcount();
            this->smartptr_count=other.smartptr_count;
            return *this;
        }


        T& operator*() const {return *myptr;}
        T* operator->() const {return myptr;}
 
    private:
        T* myptr;
        countobj* smartptr_count;     

        // void swap(const mysmartptr& rhs)  // Ϊ�˷���ʵ�ָ�ֵ��������һЩ���÷�����������Ҫһ���µ� swap ��Ա����, ��ʱ���ã�
        // {
        //     using std::swap;
        //     swap(myptr, rhs.myptr);
        //     swap(smartptr_count, rhs.smartptr_count);
        // }
};


int main() {
    mysmartptr<int> testptr(new int);
    cout<<testptr.getcount()<<endl;

        mysmartptr<int> test2 = testptr;
        cout<<testptr.getcount()<<endl;
        cout<<test2.getcount()<<endl;

    mysmartptr<int> test3;
    cout<<test3.getcount()<<endl;
    test3 = test2;
    cout<<test3.getcount()<<" "<<testptr.getcount()<<endl;
}