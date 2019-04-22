/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

#include<iostream>


using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string result="";
		int length = s.length();
		int num=2*numRows-2;
		if(numRows==1 || numRows==0 || length==0)
			return s;
		for(int i=0;i<numRows;i++)
			for(int j=i;j<length;j+=num){
				result.push_back(s.at(j));
				if(i!=0 && i!=numRows-1 && j-2*i + num<length)
					result.push_back(s.at(j-2*i + num));
			}
		return result;
	}
};








int main(){
	string s;
	Solution ans;
	int n,m;
	cin>>n>>m;
	while(n--){
		char score;
		cin>>score;
		s.push_back(score);
	}
	
	cout << s << endl;
	cout << ans.convert(s,m) << endl;
	return 0;
}






