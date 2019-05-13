#include<iostream>

using namespace std;

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
void SetSubTreeNode(TreeNode *root, TreeNode *lChild, TreeNode *rChild){
        if (root ==NULL)
            return;
        root->left = lChild;
        root->right = rChild;
}

class Solution {
private:
    bool islr(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL)
            return p==q;
        if(p->val!=q->val)
            return false;
        bool l=islr(p->left,q->right);
        bool r=islr(p->right,q->left);
        return l&&r;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return islr(root->left,root->right);
    }
};

int main(){
        Solution ans;
        TreeNode *nodeA1 = new TreeNode(1);
        TreeNode *nodeA2 = new TreeNode(2);
        TreeNode *nodeA3 = new TreeNode(2);
        TreeNode *nodeA4 = new TreeNode(3);
        TreeNode *nodeA5 = new TreeNode(4);
        TreeNode *nodeA6 = new TreeNode(4);
        TreeNode *nodeA7 = new TreeNode(3);

        SetSubTreeNode(nodeA1, nodeA2, nodeA3);
        SetSubTreeNode(nodeA2, nodeA4, nodeA5);
        SetSubTreeNode(nodeA3, nodeA6, nodeA7);


        cout << ans.isSymmetric(nodeA1) << endl;
    return 0;
}