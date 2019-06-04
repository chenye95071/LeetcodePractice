#include<iostream>
#include<map>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res="";
        int j=0;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]!='-'){
                if(j==K){
                    res+='-';
                    j=0;
                }
                if(isalnum(S[i]))
                    res+=toupper(S[i]);
                j++;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution ans;
    string a;
    cin >> a;
    int k;
    cin >> k;
    cout <<ans.licenseKeyFormatting(a,k)<< endl;
    return 0;
}