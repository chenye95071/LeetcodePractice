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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int l=maxDepth(root->left)+1;
        int r=maxDepth(root->right)+1;
        return l>r?l:r;
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


        cout << ans.maxDepth(nodeA1) << endl;
    return 0;
}