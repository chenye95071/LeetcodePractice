#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>copy=heights;
        sort(copy.begin(),copy.end());
        int res=0;
        for(auto i=0;i<heights.size();i++){
            if(heights[i]!=copy[i])
                res++;
        }
        return res;
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
    cout << ans.heightChecker(num)<< endl;
    return 0;
}