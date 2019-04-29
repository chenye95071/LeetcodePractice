/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

//一次跳一步或者两步 
//class Solution {
//public:
//    int climbStairs(int n) {
//    	vector<int>record;
//    	// 动态规划法 (利用数组来存储)
//        for(int i=0;i<n+1;i++){
//        	if(i<=1)
//        		record.push_back(1);
//        	else
//        		record.push_back(record[i-1]+record[i-2]);
//        }
//        return *(record.end()-1);
//    }
//};

//一次可以跳N步 
class Solution {
public:
    int climbStairs(int n) {
    	vector<int>record;
    	int tmp=2;
    	// 动态规划法 (利用数组来存储)
        for(int i=0;i<n+1;i++){
        	if(i<=1)
        		record.push_back(1);
        	else{
        		record.push_back(tmp);
        		tmp=tmp+*(record.end()-1);
        	}
        }
        return *(record.end()-1);
    }
};

int main(){
	Solution ans;
	int n;
	cin >> n;
	cout << ans.climbStairs(n) <<endl;
	return 0;
} 
