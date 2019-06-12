#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


class Solution {
public:
    string convertToTitle(int n) {
        map<int,char>dict;
        char tmp=65;
        string res="";
        for(int i=0;i<26;i++){
            dict[i]=tmp;
            tmp++;
        }
        while(n>0){
            n--;
            res+=dict[n%26];
            n/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


int main(){

    Solution ans;
    int m;
    cin >> m;
    cout << ans.convertToTitle(m)<<endl;
    return 0;
}


