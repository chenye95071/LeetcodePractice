#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i=0,j=0;
        int max=0,c=0;
        while(i<A.size() && j<A.size()){
            if(c<K){
                if(A[j])j++;
                else {j++;c++;}
            }else{
                if(A[j])j++;
                else {
                    if(A[i])i++;
                    else {c--;i++;}
                }
            }
            max=max>j-i?max:j-i;
        }
        return max;
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
    int k;
    cin >> k;
    cout << ans.longestOnes(num,k)<< endl;
    return 0;
}