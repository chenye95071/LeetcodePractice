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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL)return p==q;
        if(p->val != q->val) return false;
        bool l=isSameTree(p->left,q->left);
        bool r=isSameTree(p->right,q->right);
        return l&&r;
    }
};

int main(){
        Solution ans;
        TreeNode *nodeA1 = new TreeNode(8);
        TreeNode *nodeA2 = new TreeNode(8);
        TreeNode *nodeA3 = new TreeNode(7);
        TreeNode *nodeA4 = new TreeNode(9);
        TreeNode *nodeA5 = new TreeNode(2);
        TreeNode *nodeA6 = new TreeNode(4);
        TreeNode *nodeA7 = new TreeNode(7);

        SetSubTreeNode(nodeA1, nodeA2, nodeA3);
        SetSubTreeNode(nodeA2, nodeA4, nodeA5);
        SetSubTreeNode(nodeA5, nodeA6, nodeA7);

        TreeNode *nodeB1 = new TreeNode(8);
        TreeNode *nodeB2 = new TreeNode(8);
        TreeNode *nodeB3 = new TreeNode(7);
        TreeNode *nodeB4 = new TreeNode(9);
        TreeNode *nodeB5 = new TreeNode(2);
        TreeNode *nodeB6 = new TreeNode(4);
        TreeNode *nodeB7 = new TreeNode(7);

        SetSubTreeNode(nodeB1, nodeB2, nodeB3);
        SetSubTreeNode(nodeB2, nodeB4, nodeB5);
        SetSubTreeNode(nodeB5, nodeB6, nodeB7);

        cout << ans.isSameTree(nodeA1,nodeB1) << endl;
    return 0;
}