/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int n=0,Pfar=0,Cfar=0,i=0;
        vector<int>::iterator it = nums.begin();
        while(Cfar< nums.size()-1){
        	n++;
        	Pfar=Cfar;
    		for(;i<=Pfar; it++,i++)
				Cfar=max(Cfar,i+*it);
        }
        return n;
    }
};



int main(){
	vector<int> nums;
	Solution ans;
	int n;
	cin >> n;
	while(n--){
		int score;
		cin >> score;
		nums.push_back(score);
	}
	cout << ans.jump(nums) <<endl;
}
