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
    int depth(TreeNode *p){
        if(p==NULL)return 0;
        int l=depth(p->left)+1;
        int r=depth(p->right)+1;
        return l>r?l:r;
    }
    bool isBalanced_root(TreeNode *root){
        if(root==NULL)return true;
        int l=depth(root->left);
        int r=depth(root->right);
        int dif=l>r?l-r:r-l;
        if(dif>1)
            return false;
        else
            return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        bool ROOT=isBalanced_root(root);
        bool L=isBalanced(root->left);
        bool R=isBalanced(root->right);
        return ROOT&&L&&R;
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
        TreeNode *nodeA8 = new TreeNode(5);
        TreeNode *nodeA9 = new TreeNode(6);
        SetSubTreeNode(nodeA1, nodeA2, nodeA3);
        SetSubTreeNode(nodeA2, nodeA4, nodeA5);
        SetSubTreeNode(nodeA3, nodeA6, nodeA7);
        SetSubTreeNode(nodeA4, nodeA8, NULL);
        SetSubTreeNode(nodeA8, nodeA9, NULL);


        cout << ans.isBalanced(nodeA1) << endl;
    return 0;
}