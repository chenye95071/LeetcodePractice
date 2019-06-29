#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include <utility>
#include<algorithm>
using namespace std;

class Solution {
private:
    int SPFA(vector<vector<int>>&g,vector<int>&visited,int N,int K){
        queue<int>q;
        vector<int>dis(N,__INT_MAX__);
        q.push(K);
        visited[K]=1;
        dis[K]=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            visited[v]=0;
            for(int i=0;i<N;i++){
                int t=dis[v]+g[v][i];
                if (g[v][i]>=0 && dis[i]>t){
                    dis[i]=t;
                    if(!visited[i]){
                        visited[i]=1;
                        q.push(i);
                    }
                }
            }
        }
        int MAX=*max_element(dis.begin(),dis.end());
        return MAX==__INT_MAX__?-1:MAX;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int>visited(N,0);
        vector<vector<int>>g(N,vector<int>(N,-1));
        for(int i=0;i<times.size();i++){
            g[times[i][0]-1][times[i][1]-1]=times[i][2];
        }
        for(auto i:g){
            for(auto j:i)
                cout << j << " ";
            cout << endl;
        }
        return SPFA(g,visited,N,K-1);
    }
};


int main(){

    Solution ans;
    int m;
    cin >> m;
    vector<vector<int> >g(m,vector<int>(3));
    for(int i=0;i<m;i++)
        for(int j=0;j<3;j++)
            cin >> g[i][j];
    int N,K;
    cin >> N >> K;
    cout << ans.networkDelayTime(g,N,K) << endl;
    return 0;
}