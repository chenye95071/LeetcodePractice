/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     int removeDuplicates(vector<int>& nums) {
    	int i=1;
        for (vector<int>::iterator it = nums.begin()+1; i<nums.size();i++,it++){
        	if(*it==*(it-1)){
        		nums.erase(it);
        		it--;
        		i--;
			}
        }
        return nums.end()-nums.begin();
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
	cout << ans.removeDuplicates(nums) <<endl;
	for (vector<int>::iterator it = nums.begin(); it!= nums.end(); it++)
		cout << *it <<endl;
}
