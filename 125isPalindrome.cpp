#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
private:
    bool isReverse(string s,int I,int J){
        string::iterator i1=s.begin()+I,i2=s.begin()+J;
        for(;i1<i2;i1++,i2--){
            if(*i1!=*i2)
                return false;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        string tmp;
        cout << s.size() <<endl;
        for(int i=0;i<s.size();i++)
            if(isalnum(s[i])){
                tmp.push_back(tolower(s[i]));
            }
        cout << tmp <<endl;
        return isReverse(tmp,0,tmp.size()-1);
    }
};


int main(){

    Solution ans;
    string s;
    char score,ch;
    while(cin >> score){
        s.push_back(score);
    }
    cout << s << endl;
    cout << ans.isPalindrome(s) <<endl;
    return 0;
}