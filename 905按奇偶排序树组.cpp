#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0,j=A.size()-1;
        for(;i<j;){
            if(A[i]%2==1&&A[j]%2==0){
                int tmp=A[i];A[i]=A[j];A[j]=tmp;
                i++;j--;
            }else if(A[i]%2==0&&A[j]%2==1){
                i++;j--;
            }
            else if(A[i]%2==1&&A[j]%2==1)
                j--;
            else
                i++;
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
    for(auto i:ans.sortArrayByParity(a))
    cout <<i<<endl;
    return 0;
}