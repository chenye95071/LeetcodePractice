#include<iostream>
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

// class Solution {
// public:
//     int minDepth(TreeNode* p) {
//         if(p==NULL)return 0;
//         if(p->left==NULL)
//             return minDepth(p->right)+1;
//         if(p->right==NULL)
//             return minDepth(p->left)+1;
//         return minDepth(p->left)<minDepth(p->right)?minDepth(p->left)+1:minDepth(p->right)+1;
//     }
// };
class Solution {
public:
    int minDepth(TreeNode* p) {
        queue<TreeNode*>q;
        if(p)
            q.push(p);
        int level=0;
        while(!q.empty()){
            level++;
            for(int i=q.size();i>0;i--){
                TreeNode *p=q.front();
                q.pop();
                if(p->left==NULL && p->right==NULL)
                    return level;
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
        }
        return 0;
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
        //SetSubTreeNode(nodeA4, nodeA8, NULL);
        //SetSubTreeNode(nodeA8, nodeA9, NULL);


        cout << ans.minDepth(nodeA1) << endl;
    return 0;
}