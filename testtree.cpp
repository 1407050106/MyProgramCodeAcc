#include <iostream>
#include<array>
#include<queue>
using namespace std;
//���ݽṹ
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;
 
//���������˳������������
void CreateBiTree(BiTree &T) {//�������Ĺ��죬�õݹ�
    char ch;
    cin >> ch;
    //��ǰ���Ϊ��
    if (ch == '#') T = NULL;
    else {
        //��ǰ��㲻��
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);//����������
        CreateBiTree(T->rchild);//����������
    }
}
 
//�ݹ��������
void PreOrder(BiTree T){
    if(T){
        cout<<T->data<<" ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
 
//�������
void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        cout<<T->data<<" ";
        InOrder(T->rchild);
    }
}
 
//�������
void SubOrder(BiTree T){
    if(T){
        SubOrder(T->lchild);
        SubOrder(T->rchild);
        cout<<T->data<<" ";
    }
}
 
//���ƶ�����
bool Copy(BiTree T, BiTree &NewT){
    if(T == NULL){
        NewT = NULL;
        return false;
    } else{
        NewT = new BiTNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }
    return true;
}
 
//������������
int Depth(BiTree T){
    if(T == NULL)
        return 0;
    else{
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m>n)
            return (m+1);
        else
            return (n+1);
    }
}
 
//����������
int NodeCount(BiTree T){
    if(T == NULL)
        return 0;
    else
        return (NodeCount(T->lchild) + NodeCount(T->rchild) + 1);
}
 
//����Ҷ�ӽڵ���
int LeafCount(BiTree T){
    if(T == NULL)
        return 0;
    if(T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return (LeafCount(T->lchild) + LeafCount(T->rchild));
}
 
int main() {
    BiTree T,NewT;
    cout<<"�밴�������˳����������,��Ԫ����#��ʾ"<<endl;
    CreateBiTree(T);
    cout<<"�������:";
    PreOrder(T);
    cout<<endl;
    cout<<"�������";
    InOrder(T);
    cout<<endl;
    cout<<"�������";
    SubOrder(T);
    cout<<endl;
    cout<<"���ƶ�����"<<endl;
    if(Copy(T,NewT)) cout<<"���Ƴɹ�"<<endl;
    cout<<"�����������Ϊ:"<<Depth(T)<<endl;
    cout<<"�������"<<NodeCount(T)<<endl;
    cout<<"Ҷ�ӽڵ�����"<<LeafCount(T)<<endl;
    return 0;
}
