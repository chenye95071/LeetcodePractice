#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;


class Solution {
// 超时
// bool judge(vector<int>row1,vector<int>row2){
//     int len=row1.size();
//     int flag1=1,flag2=1;
//     for(int i=0;i<len;i++){
//         if(flag1||flag2){
//             if(row1[i]==row2[i])
//                 flag2=0;
//             else flag1=0;
//         }
//     }
//     if(flag1 || flag2) return true;
//     else return false;
// }
private:
    bool judgeEqual(vector<vector<int>>& matrix,int m,int n){
        for(int i=0;i<matrix[m].size();i++)
            if(matrix[m][i]!=matrix[n][i])
                return false;
        return true;
    }
    bool judgeCounter(vector<vector<int>>& matrix,int m,int n){
        for(int i=0;i<matrix[m].size();i++)
            if(matrix[m][i]+matrix[n][i]!=1)
                return false;
        return true;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==1)return 1;
        int col=matrix[0].size();
        if(col==1)return row;
        int res=1;
        for(int i=0;i<row;i++){
            int tmp=1;
            for(int j=i+1;j<row;j++){
                if(judgeEqual(matrix,i,j)||judgeCounter(matrix,i,j))
                    tmp++;
            }
            res=tmp>res?tmp:res;
        }
        return res;
    }
};


int main(){

    Solution ans;
    int m,n;
    cin >> m>>n;
    vector<vector<int> >g(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> g[i][j];
    cout << ans.maxEqualRowsAfterFlips(g) << endl;
    return 0;
}


