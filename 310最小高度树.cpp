#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)return vector<int>();
        if(n==1 ||edges.empty() )return {0};
        vector<int>res;
        queue<int>q;
        vector<unordered_set<int> >graph(n);
        for(auto i:edges){
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        for(int i=0;i<n;i++)
            if(graph[i].size()==1)
                q.push(i);
        while(n>2){
            int len=q.size();
            n-=len;
            for(int i=0;i<len;i++){
                int tmp=q.front();
                q.pop();
                for(auto e:graph[tmp]){
                    graph[e].erase(tmp);
                    if(graph[e].size()==1)
                        q.push(e);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};


int main(){

    Solution ans;
    int m,a,b;
    cin >> m;
    vector<vector<int> >g(m,vector<int>(2));
    for(int i=0;i<m;i++)
        for(int j=0;j<2;j++)
            cin >> g[i][j];
    int n;
    cin >> n;
    for(auto i:ans.findMinHeightTrees(n,g))
        cout << i<<endl;
    return 0;
}


