#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

//  �Ѿ���������
// ����ֱ���������������Ҫ��ȡ����Ϣ
struct Info{
    bool isbalanced;  // �Ƿ���ƽ��
    int height;  // �Լ����ĸ߶�
    Info() {};
    Info(bool i, int h):isbalanced(i),height(h) {};
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value) {};
    TreeNode(){};
};

class ConstructTree{
    public:
        TreeNode* CreateTree(TreeNode* node)
        {
            int input;
            cin>>input;
            if (input==0) {return nullptr;}
            else {
                node = new TreeNode(input);
                //root->val=input;
                node->left = CreateTree(node->left);
                node->right = CreateTree(node->right); 
            }
            return node;
        }

        void PrintTree(TreeNode* root)
        {
            if (!root) return;
            cout<<root->val<<" ";
            PrintTree(root->left);
            PrintTree(root->right);
        }

        // 
        bool isAVL(TreeNode* head)
        {
            // �����õݹ�����ж���������������ε��õݹ麯���أ�
           return process(head).isbalanced;
        }

        // �ݹ麯�������롢�����Ҫ���Info�ṹ���
        Info process(TreeNode* head)
        {
            if (head==nullptr) return Info(true, 0);
            Info leftinfo = process(head->left);
            Info rightinfo = process(head->right);
            // ÿһ��ݹ飬��Ҫ���㵱ǰͷ�ĸ߶Ⱥ��Ƿ�ƽ��
            int height = max(leftinfo.height, rightinfo.height)+1;
            bool balanced = true;
            if(!leftinfo.isbalanced) balanced=false;
            if(!rightinfo.isbalanced) balanced=false;
            if(abs(leftinfo.height-rightinfo.height)>1) balanced=false;
            return Info(balanced, height);
        }
};
int main() {
    ConstructTree bt;
    TreeNode* root;
    TreeNode* head;
    root = bt.CreateTree(head);

    bt.PrintTree(root);
    printf("\n");
    
    cout<<bt.isAVL(root)<<endl;
}