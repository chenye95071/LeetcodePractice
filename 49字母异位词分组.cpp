#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//最后一个样例超时
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        if(strs.empty())return res;
        int len=strs.size();
        vector<int>visited(len,0);
        map<int,map<char,int>>M;
        for(int i=0;i<len;i++)
            for(int j=0;j<strs[i].size();j++)
                M[i][strs[i][j]]++;

        for(int i=0;i<len;i++){
            if(visited[i])
                continue;
            vector<string>tmp;
            visited[i]=1;
            tmp.push_back(strs[i]);
            for(int j=i+1;j<len;j++){
                if(visited[j])
                    continue;
                if(M[i]==M[j]){
                    visited[j]=1;
                    tmp.push_back(strs[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

// 散列法
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>>res;
//         map<string,vector<string>>M;
//         for(auto &i:strs){
//             string tmp=i;
//             sort(i.begin(),i.end());
//             M[i].push_back(tmp);
//         }
//         for(auto i=M.begin();i!=M.end();i++)
//             res.push_back(i->second);
//         return res;
//     }
// };
int main(){
    Solution ans;
    int n;
    string tmp;
    vector<string>S;
    cin >> n;
    while (n--){
        cin >> tmp;
        S.push_back(tmp);
    }
    for(auto i:ans.groupAnagrams(S)){
        for(auto j:i)
            cout << j <<" ";
        cout << endl;
    }
    return 0;
}