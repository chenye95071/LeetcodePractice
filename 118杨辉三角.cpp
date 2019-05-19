#include<iostream>
#include<vector>
using namespace std;




class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res(numRows,vector<int>());
        if(numRows==0)return res;
        res[0].push_back(1);
        if(numRows==1)return res;
        res[1].push_back(1);
        res[1].push_back(1);
        for(int i=2;i<numRows;i++)
            for(int j=0;j<i+1;j++){
                if(j==0||j==i)
                    res[i].push_back(1);
                else{
                    res[i].push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
        return res;
    }
};


int main(){
    Solution ans;
    int n;
    cin >> n;
    vector<vector<int>> ANS = ans.generate(n);
    for(auto i:ANS){
        for(auto j:i)
            cout << j << " " ;
        cout<<endl;
    }
    return 0;
}