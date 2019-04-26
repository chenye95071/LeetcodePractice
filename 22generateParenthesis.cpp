#include<iostream>
#include<vector>
using namespace std;


class Solution {
private:
    vector<string>ans;
    void Traceback(string S,int left,int right,int n){
        if (S.size()==2*n) {
            ans.push_back(S);
            return;
        }
        if(left<n)
            Traceback(S+"(",left+1,right,n);
        if(right<left)
            Traceback(S+")",left,right+1,n);
    }    
public:
    vector<string> generateParenthesis(int n) {
        string S="";
        int left=0,right=0;
        Traceback(S,left,right,n);
        return ans;
    }
};

int main(){
    Solution a;
    int n;
    cin >> n;
    vector<string>ANS=a.generateParenthesis(n);
    for(vector<string>::iterator it = ANS.begin(); it != ANS.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}