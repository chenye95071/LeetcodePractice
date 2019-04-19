/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

////map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result;
    	map<int,int>numMap;
    	int i=0;
    	int temp_value,temp_key;
    	for (vector<int>::iterator it = nums.begin(); it!= nums.end(); it++){
    		if(!numMap.count(*it)){
    			numMap.insert(pair<int,int>(*it,i));
    			i++;
			}
			else{
				temp_value=*it;
				temp_key=it-nums.begin();
				i++;
			}
		}
		cout << temp_value << ' ' << temp_key <<endl;
		for (map<int,int>::iterator it1 = numMap.begin(); it1!= numMap.end(); it1++ ){
			map<int,int>::iterator it2 = numMap.find(target- (it1->first));
			if(it2!=numMap.end()&&(!(temp_value==target-it1->first))){
		//		cout << target << ' ' << target- (it1->first)<< ' '<< it2->first << ' '<< it1->second << ' ' <<it2->second<<endl;
				if (it1->second<it2->second){
					result.push_back(it1->second);
					result.push_back(it2->second);
				}
				else if(it1->second>it2->second){
					result.push_back(it2->second);
					result.push_back(it1->second);
				}
				break;
			}
			else if(temp_value==target-it1->first){
				if (it1->second<temp_key){
					result.push_back(it1->second);
					result.push_back(temp_key);
				}
				else if(it1->second>temp_key){
					result.push_back(temp_key);
					result.push_back(it1->second);
				}
				break;
			}
		}
	return result;
	}
};
////≈≈–Ú+2∑÷≤È’“ 
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//    	vector<int> result;
//    	vector<int> copy=nums;
//    	int ans1,ans2;
//        sort(nums.begin(),nums.end());
//        for (vector<int>::iterator begin = nums.begin(),end=nums.end()-1; begin!= end; ){
//         	if(*begin + *end > target)
//         		end--;
//         	else if(*begin + *end < target)
//         		begin++;
//         	else if(*begin + *end == target){
//         		ans1=*begin;
//         		ans2=*end;
//         		break;
//			}
//    	}
//    	if(ans1 ==ans2){
//    		for (vector<int>::iterator it1 = copy.begin(); it1!= copy.end(); it1++ ){
//    			if(*it1 == ans1)
//    				result.push_back(it1-copy.begin());
//    		}
//    	}
//    	else if (ans1!=ans2){
//    		for (vector<int>::iterator it = copy.begin(); it!= copy.end(); it++ ){
//    			if(*it == ans1)
//    				result.push_back(it-copy.begin());
//    			if(*it == ans2)
//    				result.push_back(it-copy.begin());
//    		}
//    	}
//    	sort(result.begin(),result.end());
//    	return result;
//	}
//};
    	

int main(){
	vector<int> a,answer;
    int n ,tar,score;
    char sym1,sym2;
    Solution ans;
    cin >> n;
    while (n--){
    	cin >>score;
        a.push_back(score);
    }

    cin >> tar;
    answer = ans.twoSum(a,tar);
    cout << "[" << *answer.begin()<<"," <<*(answer.end()-1)<<"]"<<endl;
	return 0;
}

