#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res=0,pos1=0,pos2=1;
        map<int,int>T;//篮子，只装两类
        T[tree[0]]=1;
        for(int i=1;i<tree.size();i++){
            if(T[tree[i]]!=0){//已经遇到过的种类 直接计数
                pos2++;
            }else if(T.size()<2){//没遇到过的种类  但有篮子没装，相应的篮子置1 继续计数
                T[tree[i]]=1;
                pos2++;
            }else{//没遇到过的种类  篮子装满了  更新记录  pos2从新类前的旧类数开始计数
                res=res>pos2?res:pos2;
                pos2=i-pos1+1;
                T.clear();//将篮子清空，只装当前新类和上一个旧类 
                T[tree[i]]=1;
                T[tree[i-1]]=1;
            }
            if(tree[i]!=tree[i-1])//遇到类别变更 将计数起点更新
                pos1=i;
        }
        res=res>pos2?res:pos2;//最后一次计数完后再更新一次
        return res;
    }
};

int main(){
    Solution ans;
    int n;
    cin >> n;
    vector<int>num;
    while (n--){
        int score;
        cin >> score;
        num.push_back(score);
    }
    cout << ans.totalFruit(num) << endl ;
    return 0;
}