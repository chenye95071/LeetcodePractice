#include<iostream>
#include<map>
#include<vector>
#include<cctype>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int min=0,max=S.size();
        vector<int>res;
        for(int i=0;i<S.size();i++){
            if(S[i]=='I')
                res.push_back(min++);
            else
                res.push_back(max--);
        }
        res.push_back((min+max)/2);
        return res;
    }
};


int main(){
    Solution ans;
    string a;
    cin >> a;
    for(auto i:ans.diStringMatch(a))
        cout <<i<< endl;
    return 0;
}