#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis_self=abs(target[0])+abs(target[1]);
        for(int i=0;i<ghosts.size();i++){
            int dis_ghost=abs(target[0]-ghosts[i][0])+abs(target[1]-ghosts[i][1]);
            //cout <<dis_self<<" " << dis_ghost<<endl;
            if(dis_self>=dis_ghost)
                return false;
        }
        return true;
    }
};


int main(){

    Solution ans;
    int m,a,b;
    cin >> m;
    vector<vector<int> >g(m,vector<int>(2));
    vector<int>t(2);
    for(int i=0;i<m;i++)
        for(int j=0;j<2;j++)
            cin >> g[i][j];
    for(int i=0;i<2;i++)
        cin >> t[i];
    cout <<"t " << t[0] << " " << t[1] <<endl;
    cout << ans.escapeGhosts(g,t)<<endl;
    return 0;
}


