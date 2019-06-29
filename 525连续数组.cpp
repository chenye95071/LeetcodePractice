#include<iostream>
#include<vector>
#include<map>
using namespace std;
// 更巧妙
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums)
//     {
//         int res = 0, n = nums.size(), sum = 0;
//         unordered_map<int, int> m{{0, -1}};
//         for (int i = 0; i < n; ++i)
//         {
//             sum += (nums[i] == 1) ? 1 : -1;
//             cout << sum << endl;
//             if (m.count(sum))
//             {
//                 res = max(res, i - m[sum]);
//             }
//             else
//             {
//                 m[sum] = i;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.empty())return 0;
        map<int,int>T;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
                nums[i]=-1;//所有的0变-1
        int sum=0,res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==0){
                if(i>=res)
                    res=i+1;//和为0，更新计数起点；
            }
            if(T.find(sum)==T.end()){//不存在 则继续计数
                T[sum]=i;
                continue;
            }
            int t=i-T[sum];  //存在 则更新这一段的长度
            if(t>res)
                res=t;
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
    cout << ans.findMaxLength(num) << endl ;
    return 0;
}