#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//思路一致 程序细节有误
// class Solution {
// private:
//     vector<int> change(vector<int>&num,int i,int j){
//         int len=j-i+1,count=0;
//         if(len<3)return num;
//         vector<int>res;
//         for(int k=i;k<=j;k++)
//             if(k%2==0){
//                 res.push_back(num[k]);count++;
//             }
//         for(int k=i;k<=j;k++)
//             if(k%2==1)
//                 res.push_back(num[k]);
//         for(int k=i;k<=j;k++){
//             num[k]=res[k-i];
//         }
//         num=change(num,0,count-1);
//         num=change(num,count,len-1);
//         return num;
//     }    
// public:
//     vector<int> beautifulArray(int N) {
//         vector<int>num(N);
//         for(int i=0;i<N;i++)
//             num[i]=i+1;
//         num=change(num,0,N-1);
//         return num;
//     }
// };
class Solution {
private:
    void change(vector<int>&num){
        int len=num.size();
        if(len<3) res.insert(res.end(),num.begin(),num.end());
        else{
            vector<int>res1,res2;
            for(int k=0;k<num.size();k++)
                if(k%2==0)
                    res1.push_back(num[k]);
                else
                    res2.push_back(num[k]);
            change(res1);
            change(res2);
        }
    }    
public:
    vector<int>res;
    vector<int> beautifulArray(int N) {
        vector<int>num(N);
        for(int i=0;i<N;i++)
            num[i]=i+1;
        change(num);
        return res;
    }
};

int main(){
    Solution ans;
    int N;
    cin >> N;
    for(auto i:ans.beautifulArray(N))
        cout << i << endl;
    return 0;
}