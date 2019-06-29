#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
#define MIN 1
#define MAX 7

int rand7(){

    return MIN+(unsigned int)rand()%MAX;
}

// class Solution {
// public:
//     int rand10() {
//         int i;
//         do{
//             i=7*(rand7()-1)+rand7();
//         }while(i>40);
//         return i%10+1;
//     }
// };
class Solution {
public:
    int rand10() {
        int table[7][7]={
            {1,2,3,4,5,6,7},
            {8,9,10,1,2,3,4},
            {5,6,7,8,9,10,1},
            {2,3,4,5,6,7,8},
            {9,10,1,2,3,4,5},
            {6,7,8,9,10,0,0},
            {0,0,0,0,0,0,0},
        };
        int res=0;
        while(res==0){
            int i=rand7();
            int j=rand7();
            res=table[i-1][j-1];
        }
        return res;
    }
};

int main(){
    Solution ans;
    cout<<ans.rand10()<<endl;
}