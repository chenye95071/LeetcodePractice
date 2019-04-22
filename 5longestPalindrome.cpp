/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//Use too much Time!
//bool isReverse(string::iterator b,string::iterator e){
//	for(;b!=e&&b+1!=e;b++,e--){
//		if(*b!=*e)
//			return false;
//	}
//	if(b+1==e)
//		if(*b!=*e)
//			return false;
//	return true;
//}

//class Solution {
//public:
//    string longestPalindrome(string s) {
//		int idx=0;
//        string max,record;
//        string::iterator ite=s.end();
//        for(string::iterator itb=s.begin();itb!=s.end();itb++){
//        	for(;ite!=itb;ite--){
//        		idx = s.find_last_of(*itb,ite-s.begin());
//        	//	cout << "idx " << idx<<endl;
//        		if(idx!=string::npos){
//			//	cout << *itb <<' ' << *(s.begin()+idx) <<endl;
//			//	cout << isReverse(itb,s.begin()+idx)<<endl;
//					if(isReverse(itb,s.begin()+idx))
//						record=s.substr(itb-s.begin(),idx-(itb-s.begin())+1);
//					else
//						record.push_back(*itb);
//				}
//				if(max.size()<=record.size())
//        			max=record;
//        		record.clear();
//        	}
//			ite=s.end();
//		}
//        return max;
//    }
//};


class Solution {
public:
	string longestPalindrome(string s){
		int max = 0;
		int idx = 0;
    	string temp[2005];
    	int j = 0;
    	for (int i = 0; i < s.size(); i++){
        	temp[j++] = '#';
        	temp[j++] = s[i];
    	}
    	temp[j++] = '#';
    	temp[j] = '\0';
    	for (int i = 0; i < 2 * s.size() + 1; i++){
        	int j = i;
        	int z = i;
        	int count = 0;
        	while ((++z) < (2 * s.size() + 1) && (--j >= 0) && (temp[z] == temp[j])){
            	count++;
            	if (count > max){
                	max = count;
                	idx = i;
            }
        }
    }
    return s.substr((idx - max) / 2, max);
	}

};


int main(){
	string s;
	Solution ans;
	int n;
	cin>>n;
	while(n--){
		char score;
		cin>>score;
		s.push_back(score);
	}
	
	//cout << s << endl;
	cout << ans.longestPalindrome(s) << endl;
	
	return 0;
}
