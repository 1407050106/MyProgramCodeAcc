#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <string.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value) {};
    TreeNode(){};
};

class SerializeAndReconstructTree{
    public:
        // ����ʽ���л����Ǹ���ͷ�ڵ㣬������˳��洢��
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

        // ����ʽ�����л�
        queue<string> serialize(TreeNode* head)
        {
            queue<string> ans;
            pres(head, ans);
            return ans;
        }

        // ����ʽ�����л�
        TreeNode* buidbypreorder(queue<string> tq)
        {
            if (tq.empty()) return nullptr;
            return preb(tq);
        }

        // ����ʽ���л��Ƚϼ�, ���ǰ��㷴���л��Ƚ���, �ʼ�����ϸ�߼�ע��
        // ע�����л�����������һ����һ����������

    private:  
        void pres(TreeNode* head, queue<string>& ans)
        {
            if (!head) 
            {ans.push("#");}    // ����Ҫ��if-else�ṹ����Ϊû��return����
            else {                              
            ans.push(to_string(head->val));
            pres(head->left, ans);
            pres(head->right, ans);}
            printf("\n");
        }

        TreeNode* preb(queue<string>& tq)
        {
            string value = tq.front();
            tq.pop();
            if (value=="#") return nullptr;
            TreeNode* root = new TreeNode(atoi(value.c_str()));
            root->left=preb(tq);
            root->right=preb(tq);
            return root;
        }
};

class pprint{
    public:
        void operator()(int val){
            cout<<val<<" ";
        }
};

int main() {
    SerializeAndReconstructTree st;
    TreeNode *root, *res;
    res = st.CreateTree(root);
    // st.PrintTree(res);
    // �������л��õ��������Ķ���
    queue<string> tt = st.serialize(res);
    // while(!tt.empty())
    // {
    //     cout<<tt.front()<<" ";
    //     tt.pop();
    // }
    // printf("\n");
    TreeNode* ft = st.buidbypreorder(tt);
    st.PrintTree(ft);
}