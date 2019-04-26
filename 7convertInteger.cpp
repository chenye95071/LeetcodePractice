/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [?231,  231 ? 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/ 

#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result=0;	
        while(x!=0){
        	//���ǰ�����ж� 
        	if(result>INT_MAX/10 || (result==INT_MAX && x%10>7))
        		return 0;
        	if(result<INT_MIN/10 || (result==INT_MIN && x%10<-8))
        		return 0;
        	result=result*10+x%10;
        	x/=10;
        }
    	return result;
    }
};

int main(){
	Solution ans;
	int n;
	cin >> n;
	cout << n << endl;
	cout << ans.reverse(n) <<endl;
	return 0;
}
