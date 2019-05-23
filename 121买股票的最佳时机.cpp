#include<iostream>
#include<vector>
using namespace std;



//贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)return 0;
        int minValue=prices[0];
        int maxDif=0;
        for(int i=0;i<prices.size();i++){
            if(maxDif<prices[i]-minValue)
                maxDif=prices[i]-minValue;
            if(minValue>prices[i])
                minValue=prices[i];
        }
        return maxDif;
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