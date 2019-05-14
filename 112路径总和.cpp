#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
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
    bool hasPath(TreeNode* root,int sum){
        if(root==NULL)return false;
        if(root->left==NULL && root->right==NULL){
            if(root->val != sum)
                return false;
            return true;
        }
        bool l=hasPath(root->left,sum-root->val);
        bool r=hasPath(root->right,sum-root->val);
        return l||r;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPath(root,sum);
    }
};

int main(){
        Solution ans;
        TreeNode *nodeA1 = new TreeNode(5);
        TreeNode *nodeA2 = new TreeNode(4);
        TreeNode *nodeA3 = new TreeNode(8);
        TreeNode *nodeA4 = new TreeNode(11);
        TreeNode *nodeA5 = new TreeNode(13);
        TreeNode *nodeA6 = new TreeNode(4);
        TreeNode *nodeA7 = new TreeNode(7);
        TreeNode *nodeA8 = new TreeNode(2);
        TreeNode *nodeA9 = new TreeNode(1);

        SetSubTreeNode(nodeA1, nodeA2, nodeA3);
        SetSubTreeNode(nodeA2, nodeA4,  NULL);
        SetSubTreeNode(nodeA3, nodeA5, nodeA6);
        SetSubTreeNode(nodeA4, nodeA7, nodeA8);
        SetSubTreeNode(nodeA6, NULL, nodeA9);

        TreeNode *nodeB1 =new TreeNode(1);
        TreeNode *nodeB2 =new TreeNode(2);
        SetSubTreeNode(nodeB1,nodeB2,NULL);
        int sum;
        cin >> sum;
        cout << ans.hasPathSum(nodeB1,sum) << endl;
    return 0;
}