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

void preOrder(TreeNode *p){
    if(p==NULL)return;
    cout << p->val << endl;
    preOrder(p->left);
    preOrder(p->right);
}
void inOrder(TreeNode *p){
    if(p==NULL)return;
    preOrder(p->left);
    cout << p->val << endl;
    preOrder(p->right);
}
void postOrder(TreeNode *p){
    if(p==NULL)return;
    postOrder(p->left);
    postOrder(p->right);
    cout << p->val << endl;
}
class Solution {
private:
    TreeNode *sortedArrayToBST(vector<int>& nums,int left,int right){
        if(left>right)return NULL;
        int mid=(left + right)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums,left,mid-1);
        root->right=sortedArrayToBST(nums,mid+1,right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
};

    void BFS(vector<vector<int>>& result,int level,TreeNode* root){
        if(root==NULL)return;
        while(result.size()<=level)
            result.emplace_back(vector<int>());
        result[level].emplace_back(root->val);
        //cout << "left" << " ";
        BFS(result,level+1,root->left);
        //cout << "right" << " ";
        BFS(result,level+1,root->right);
        //cout << endl;
    }
int main(){
        Solution ans;
        // TreeNode *nodeA1 = new TreeNode(3);
        // TreeNode *nodeA2 = new TreeNode(9);
        // TreeNode *nodeA3 = new TreeNode(20);
        // TreeNode *nodeA4 = new TreeNode(3);
        // TreeNode *nodeA5 = new TreeNode(4);
        // TreeNode *nodeA6 = new TreeNode(15);
        // TreeNode *nodeA7 = new TreeNode(7);

        // SetSubTreeNode(nodeA1, nodeA2, nodeA3);
        // SetSubTreeNode(nodeA2, NULL,  NULL);
        // SetSubTreeNode(nodeA3, nodeA6, nodeA7);
        int n;
        cin >> n;
        vector<int>num;
        while(n--){
            int score;
            cin >> score;
            num.emplace_back(score);
        }
        TreeNode *p=ans.sortedArrayToBST(num);
        vector<vector<int>>res;
        BFS(res,0,p);
        for(auto i:res){
            for(auto j:i)
                cout << j << " ";
            cout << endl;
        }
         preOrder(p);
         inOrder(p);
         postOrder(p);
    return 0;
}