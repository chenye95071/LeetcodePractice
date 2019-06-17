#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
        int min=__INT_MAX__,min2=__INT_MAX__;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=min)
                min=nums[i];
            else if(nums[i]<=min2)
                min2=nums[i];
            else 
                return true;
        }
        return false;
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
    cout << ans.increasingTriplet(num) << endl ;
    return 0;
}