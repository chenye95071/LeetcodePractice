#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
private:
    bool Judge(vector<string>& board){
        int numX=0,numO=0;
        for(auto i:board)
            for(auto j:i){
                if(j=='X')numX++;
                if(j=='O')numO++;
            }
        if(numO>numX || numX>numO+1)   //X先手其数量不能少于O  轮换下则X不能比O数量多出一个以上
            return false;

        int num1=0,num2=0,num3=0;int flag=0;
        for(auto i:board){//统计横向
            if(i=="XXX")num1++;
            if(i=="OOO"){num1++;flag=1;}
        }
        for(int i=0;i<3;i++){//统计纵向
            if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X')num2++;
            if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O'){num2++;flag=1;}
        }
        //斜向
        if((board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X') || (board[2][0]=='X' && board[1][1]=='X' && board[0][2]=='X'))num3++;
        if((board[2][0]=='O' && board[1][1]=='O' && board[0][2]=='O') ||  (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')){num3++;flag=1;}
        
        if(num1+num2+num3>1){  //出现两种以上胜利情况
            if(numX==5 && numO==4 &&((num1==1 && num2==1) || (num3==2)) )  //两种胜利情况正确仅在  X=5,O=4且X存在公用
                return true;
            else return false;  //其余情况均错
        }
        else if(num1+num2+num3 ==1 && flag==1 && numX!=numO)//一种胜利情况时的错误情况仅在  赢后不能再下 故需要区分X赢和O赢  这里用flag标识
            return false; //O赢X与O数量必相等
        else if(num1+num2+num3 ==1 && flag==0  && numX==numO)
            return false; //X赢X数量必大于O
        else return true;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        return Judge(board);
    }
};


int main(){

    Solution ans;
    vector<string>b;
    int i=3;
    while(i--){
        string score;
        getline(cin,score);
        b.push_back(score);
    }
    // for(auto i:b)
    //     cout << i << endl;
    cout << ans.validTicTacToe(b)<<endl;
    return 0;
}