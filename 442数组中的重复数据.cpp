#include<iostream>
#include<vector>
#include<map>
using namespace std;


//通过  98.12%  但使用了额外空间
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int>count(nums.size()+1,0);
//         vector<int>res;
//         for(int i=0;i<nums.size();i++){
//             count[nums[i]]++;
//             if(count[nums[i]]==2)
//                 res.push_back(nums[i]);
//         }
//         return res;
//     }
// };

//参考讨论区 解法  输入输出的空间不属于额外空间，
//可以在输入数组中用数字的正负来表示该位置所对应数字是否已经出现过。
//遍历输入数组，给对应位置的数字取相反数，如果已经是负数，说明前面已经出现过，直接放入输出数组。
//91.2%
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]*=-1;
            }else{
                res.push_back(abs(nums[i]));
            }
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
    for(auto i:ans.findDuplicates(num))
        cout << i << endl ;
    return 0;
}