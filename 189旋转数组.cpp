#include<iostream>
#include<map>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        k%=len;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};


int main(){
    Solution ans;
    int m;
    cin >> m;
    int i;
    i=m;
    vector<int>a(m);
    while(i--){
        cin >> a[m-i-1];
    }
    int k;
    cin >>k;
    ans.rotate(a,k);
    for(auto i:a)
        cout << i << endl;
    return 0;
}