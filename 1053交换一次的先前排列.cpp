#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int flag=0,record_i=0,record_j=0;
        for(int i=A.size()-2;i>=0;i--){
            if(A[i]>A[i+1]){
                record_i=i;
                for(int j=A.size()-1;j>i;j--){
                    if(A[j]<A[i]){
                        if(!flag)
                            record_j=j;
                        flag=1;
                        if(flag && A[record_j]!=A[j])
                            break;
                        record_j=j;
                    }
                }
                if(flag)
                    break;
            }
        }
        if(flag){
            int tmp=A[record_j];
            A[record_j]=A[record_i];
            A[record_i]=tmp;
        }
        return A;
    }
};


int main(){
    Solution ans;
    int m;
    cin >> m;
    int i;
    i=m;
    vector<int>a(m);
    while(i--){
        cin >> a[m-i-1];
    }
    for(auto i:ans.prevPermOpt1(a))
        cout <<i<<endl;
    return 0;
}