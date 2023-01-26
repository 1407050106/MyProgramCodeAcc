#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int value):val(value){};
    //TreeNode():val(0){};
};

TreeNode* getsnode(TreeNode* node);
TreeNode* getleftmost(TreeNode* node);

TreeNode* getsnode(TreeNode* node)
{
    if (node == nullptr) return nullptr;
    if (node->right)
    {
        return getleftmost(node->right);
    } else {   // ��������
        // ����Ҫע������д������parent����д����(������д����Ҳ��)
        TreeNode* parent = node->parent;
        while (parent!=nullptr && parent->right==node)
        {
            node = parent;
            parent = node->parent;
        }
        return parent;
    }
}

TreeNode* getleftmost(TreeNode* node)
{
    if (node->left==nullptr) return node;
    while (node->left!=nullptr)  // ��������������ڵ�
    {
        node =  node->left;
    }
    return node;
}

int main() 
{
    TreeNode* head = new TreeNode(1);
    head->parent = nullptr;

    head->left = new TreeNode(2);
    head->left->parent = head;
    head->right = new TreeNode(3);
    head->right->parent = head;

    head->left->left = new TreeNode(4);
    head->left->left->parent = head->left;
    head->left->right = new TreeNode(5);
    head->left->right->parent = head->left;
    
    TreeNode* res = getsnode(head);
    cout<<res->val<<endl;
}