#include<iostream>
#include<vector>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        if(head==NULL || head->next==NULL)return head;
        while(head!=NULL && head->next!=NULL){
            if(head->val==head->next->val){
                head->next=head->next->next;
                continue;
            }
            head=head->next;
        }
        return p;
    }
};

int main(){

    int n,score;
    Solution ans;
    ListNode *root=new ListNode(0);
    ListNode *p=root;
    cin >> n;
    while(n--){
        cin >> score;
        p->val=score;
        if(!n)
            break;
        p->next=new ListNode(0);
        p=p->next;
    }
    
    ListNode *ANS=ans.deleteDuplicates(root);
    while(ANS!=NULL){
        cout << ANS->val <<endl ;
        ANS=ANS->next;
    }
    return 0;
}