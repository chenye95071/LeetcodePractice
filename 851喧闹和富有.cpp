#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

class Solution {
private:
    int DFS(map<int,vector<int>>&rich,int ves,vector<int>& quiet,vector<int> &res){
        if(res[ves]>=0)//判断是否访问过 加快速度
            return res[ves];
        res[ves]=ves;//初值设为自身 自身属于富有程度不少于自身的人中
        for(int i=0;i<rich[ves].size();i++)
            if(quiet[res[ves]]>quiet[DFS(rich,rich[ves][i],quiet,res)])//寻找更安静的人并更新
                res[ves]=res[rich[ves][i]];
        return res[ves];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        map<int,vector<int>>rich;
        vector<int>res(n,-1);//结果表 初始为-1同时也起到visited的效果
        for(int i=0;i<richer.size();i++)//邻接表表示比richer[i][1]更富有的人
            rich[richer[i][1]].push_back(richer[i][0]); 
        for(int i=0;i<n;i++)
            DFS(rich,i,quiet,res);//对每一个人深度优先搜索更富有的人中最安静的人
        return res;
    }
};


int main(){

    Solution ans;
    int m,n,a,b;
    cin >> m>>n;
    vector<vector<int> >g(m,vector<int>(2));
    vector<int>t(n);
    for(int i=0;i<m;i++)
        for(int j=0;j<2;j++)
            cin >> g[i][j];
    for(int i=0;i<n;i++)
        cin >> t[i];
    for(auto i:ans.loudAndRich(g,t))
        cout << i<<endl;
    return 0;
}


