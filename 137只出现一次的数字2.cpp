#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0,b=0;
        for(auto i:nums){
            a=(a^i)&~b;
            b=(b^i)&~a;
        }
        return a;
    }
};


int main(){
    Solution ans;
    int n;
    cin >> n;
    vector<int>num;
    while (n--){
        int score;
        cin >> score;
        num.push_back(score);
    }
    
    cout << ans.singleNumber(num) << endl ;
    return 0;
}