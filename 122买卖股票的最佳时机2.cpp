#include<iostream>
#include<vector>
using namespace std;



//可以卖出后当天立即再买入
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)return 0;
        int sum=0;
        int minValue=prices[0];
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]-prices[i]>0)
                sum+=prices[i+1]-prices[i];
        }
        return sum;
    }
};


int main(){
    Solution ans;
    int n;
    cin >> n;
    vector<int>price;
    while (n--){
        int score;
        cin >> score;
        price.push_back(score);
    }
    
    cout << ans.maxProfit(price) << endl ;
    return 0;
}