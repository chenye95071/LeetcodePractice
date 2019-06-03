#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    bool canmake(int a,int b,int c,int d){
        if(a==2 && b<=3 && c<=5)return true;
        if(a<=1 && c<=5)return true;
        return false;
    }
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end(),greater<int>());
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                if(j==i)continue;
                for(int m=0;m<4;m++){
                    if(m==i||m==j)continue;
                    for(int n=0;n<4;n++){
                        if(n==i||n==j||n==m)continue;
                        if(canmake(A[i],A[j],A[m],A[n]))
                            return to_string(A[i])+to_string(A[j])+':'+to_string(A[m])+to_string(A[n]);
                    }
                }
            }
        return "";
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
    
    cout <<ans.largestTimeFromDigits(a)<<endl;
    return 0;
}