#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int len=customers.size();
        int dp=0;
        for(auto i=0;i<len;i++){
            if(!grumpy[i])
                dp+=customers[i];
        }
        int max=0;
        for(auto i=0;i<len-X+1;i++){
            int tmp=0;
            for(auto j=i;j<i+X;j++){
                if(grumpy[j])
                    tmp+=customers[j];
            }
            max=max>tmp?max:tmp;
        }
        return dp+max;
    }
};


int main(){
    Solution ans;
    int m;
    cin >> m;
    int i,j;
    i=j=m;
    vector<int>a(m),b(m);
    while(i--){
        cin >> a[m-i-1];
    }
    while(j--){
        cin >> b[m-j-1];
    }
    int x;
    cin >>x;
    cout << ans.maxSatisfied(a,b,x)<<endl;
    return 0;
}