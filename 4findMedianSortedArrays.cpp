/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

 

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int sym=((nums1.size()+nums2.size())%2==0)?0:1;
    	int idx=(nums1.size()+nums2.size())/2;
    	vector<int>::iterator it1=nums1.begin(),it2=nums2.begin();
    	vector<vector<int>::iterator> last_record;
    	if(nums1.empty()&&nums2.empty())	return 0.0;
        if(nums1.empty()&&!nums2.empty())	return sym? (double)nums2[idx]: ((double)nums2[idx]+nums2[idx-1])/2.0;
        if(nums2.empty()&&!nums1.empty())	return sym? (double)nums1[idx]: ((double)nums1[idx]+nums1[idx-1])/2.0;
        if(!nums1.empty() && !nums2.empty()){
			for(int i=0;i<idx;i++){
				if(it2==nums2.end()-1 && it1==nums1.end()-1 ){
					if(*it1<=*it2){
						last_record.push_back(it1);
						last_record.push_back(it2);		
					}
					else{
						last_record.push_back(it2);
						last_record.push_back(it1);
					}
				}
				else if(it2!=nums2.end()-1 || it1!=nums1.end()-1){
					if(it1==nums1.end()-1 && it2!=nums2.end()-1){
						if(*it1<=*it2){
							last_record.push_back(it2);it2++;
						}
						else{
							it2++;if(*it1<=*it2)last_record.push_back(it1);else last_record.push_back(it2);
						}
					}
					if(it2==nums2.end()-1 && it1!=nums1.end()-1){
						if(*it1<=*it2){
							it1++;if(*it1<=*it2)last_record.push_back(it1);else last_record.push_back(it2);
						}
						else{
							last_record.push_back(it1);it1++;
						}
					}
				}
				if(it1!=nums1.end()-1 && it2!=nums2.end()-1)
				{
					if(*it1<=*it2){
						it1++;if(*it1<=*it2)last_record.push_back(it1);else last_record.push_back(it2);
						
					}
					else{
						it2++;if(*it1<=*it2)last_record.push_back(it1);else last_record.push_back(it2);
					}
				}
        	}
        }
        return sym? (double)**(last_record.end()-1) : ((double)**(last_record.end()-1) +**(last_record.end()-2))/2.0;
    }
};

int main(){
	Solution ans;
	vector<int>nums1,nums2;
	int m,n;
	cin >> m >> n;
	while(m--){
		double score;
		cin >> score;
		nums1.push_back(score);
	}
	while(n--){
		double score;
		cin >> score;
		nums2.push_back(score);
	}
	cout << ans.findMedianSortedArrays(nums1,nums2) <<endl;
	return 0;
} 
