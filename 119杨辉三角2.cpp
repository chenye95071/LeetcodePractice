#include<iostream>
#include<vector>
using namespace std;




class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res(rowIndex+1,0);
        res[0]=1;
        for(int i=1;i<=rowIndex;i++)
            for(int j=i;j>0;j--)
                    res[j]=res[j]+res[j-1];    
        return res;
    }
};


int main(){
    Solution ans;
    int n;
    cin >> n;
    vector<int> ANS = ans.getRow(n);
    for(auto i:ANS)
            cout << i << " " ;
    cout<<endl;
    return 0;
}