#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
private:
    void fun(string A,map<string,int>&R){
        int s=0,e;
        for(int i=0;i<A.size();i++){ 
            if(A[i]==' '){
                e=i;
                //cout<<"test: " <<s<<" "<<e<<" "<< A.substr(s,e-s) << endl;
                R[A.substr(s,e-s)]++;
                s=i+1;
            }
            if(i==A.size()-1)
                R[A.substr(s,A.size()-s)]++;
        }
    }
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string>res;
        map<string,int>R;
        fun(A,R);
        fun(B,R);
        for(auto i=R.begin();i!=R.end();i++){
            //cout << (*i).first <<endl;
            if((*i).second==1)
                res.push_back((*i).first);
        }
        return res;
    }
};


int main(){
    Solution ans;
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(auto i:ans.uncommonFromSentences(a,b))
        cout << i << endl;
    return 0;
}