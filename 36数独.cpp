#include<iostream>
#include<vector>

using namespace std;
class Solution {
private:
    int _toSeq(int i){
        if(i<3)
            return 1;
        else if(i<6)
            return 2;
        else
            return 3; 
    }
    int _toUnit(int i,int j){
        if(_toSeq(i)==1)
            return _toSeq(i)+_toSeq(j)-2;
        else if(_toSeq(i)==2)
            return _toSeq(i)+_toSeq(j);
        else
            return _toSeq(i)+_toSeq(j)+2;
    }

    bool check(int (*num)[10]){
        for(int i = 0; i < 9; i++){
            for(int j = 1; j <= 9; j++){
                if(num[i][j]>1)
                    return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col[9][10]={0};
        int row[9][10]={0};
        int unit[9][10]={0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j]!='.') {
                    col[j][board[i][j]-'0']++;
                    row[i][board[i][j]-'0']++;
                    unit[_toUnit(i,j)][board[i][j]-'0']++;
                }       
            }
        }
    if(check(col) && check(row) && check(unit))
        return true;
    return false; 
    }

};

int main(){
    Solution ans;
    vector<vector<char>> board(9, vector<char>(9,'.'));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin>>board[i][j];
        }
        
    }
    cout << ans.isValidSudoku(board) << endl;
    return 0;
}