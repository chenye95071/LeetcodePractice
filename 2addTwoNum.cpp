/*
	You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(l1==NULL || l2==NULL)
    		return 0;
        int sym=0,n=0,sum=0;
        ListNode *ans=new ListNode(0);
        ListNode *tmp=ans;
        while(l1!=NULL || l2!=NULL){
        	int x=(l1!=NULL)?l1->val:0;
        	int y=(l2!=NULL)?l2->val:0;
        	int sum=x+ y+ sym;
        	sym=sum/10;
        	ans->next= new ListNode(sum%10);
        	ans=ans->next;
        	if(l1)l1=l1->next;
			if(l2)l2=l2->next;
		}
        if(sym){
        	ans->next=new ListNode(sym);
        }
        return tmp->next;
    }
};


int main(){
	int n,m,score[100]={0},i,j;
	Solution Ans;
	cin >> n;
	ListNode *p1=new ListNode(0),*p2=new ListNode(0);
	ListNode *tmp1=p1,*tmp2=p2;
	for(i=0;i<n;i++)
		cin >> score[i];
	while(i--){
		p1->val=score[n-1-i];
		p1->next=new ListNode(0);
		p1=p1->next;
	}
	
	cin >> m;
	for(j=0;j<m;j++)
		cin >> score[j];
	while(j--){
		p2->val=score[m-1-j];
		p2->next=new ListNode(0);
		p2=p2->next;
	}
	
	ListNode *ans = Ans.addTwoNumbers(tmp1,tmp2);
	while(ans!=NULL){
		cout << ans->val <<endl;
		ans=ans->next;
	}
	
	return 0;
}





