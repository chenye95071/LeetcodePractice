#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        if(strs.empty())return res;
        if(strs[0].empty())return res;
        if(strs.size()==1)return strs[0];
        int k=0;char tmp;
        while(1){
            int flag=1;
            if(k<strs[0].size()){
                tmp = strs[0][k];
            }
            else{
                flag=0;
                break;
            }
            for(int i=1;i<strs.size();i++){
                if(k<strs[i].size()){
                    if(strs[i][k]!=tmp){
                        flag=0;
                        break;
                    }   
                }
                else{
                    flag=0;
                    break;
                }  
            }
            if(flag)
                    res+=tmp;
            else
                break;
            k++;
        }
        return res;
    }
};


int main(){

    Solution ans;
    string s;
    vector<string>S;
    int n;
    cin >>n;
    while(n--){
        cin >> s;
        S.push_back(s);
    }
       
    cout << ans.longestCommonPrefix(S) << endl;
    return 0;
}