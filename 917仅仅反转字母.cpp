#include<iostream>
#include<map>
#include<vector>
#include<cctype>
using namespace std;


class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i=0,j=S.size()-1;
        while(i<j){
            if(isalpha(S[i]) && isalpha(S[j])){
                int tmp=S[i];S[i]=S[j];S[j]=tmp;
                i++;j--;
            }else if(isalpha(S[i]) && !isalpha(S[j]))
                j--;
            else if(!isalpha(S[i]) && isalpha(S[j]))
                i++;
            else{
                i++;j--;
            }
        }
        return S;
    }
};


int main(){
    Solution ans;
    string a;
    cin >> a;
    cout <<ans.reverseOnlyLetters(a)<< endl;
    return 0;
}