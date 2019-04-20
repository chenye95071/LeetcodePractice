/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx=0,max=0,record=0;
        string tmp;
        for(string::iterator it=s.begin();it!=s.end();it++){
        	idx=tmp.find(*it);
    //    	cout <<"place"<<idx<<endl;
        	if(idx==string::npos){
        		tmp.push_back(*it);
        		record++;
        	}
        	else{
        		tmp.erase(0,idx+1);
           		tmp.push_back(*it);
	//			cout <<"length:"<<tmp<<endl;
        		if(tmp.size()==1)
        			record=1;
        		else
        			record=tmp.size();
        	}
        	if(max<=record)
        		max=record;
		}
        return max;
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
	
	cout << s << endl;
	cout << ans.lengthOfLongestSubstring(s) << endl;
	return 0;
}
