#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0||nums1.empty()){nums1=nums2;return;}
        if(n==0||nums2.empty())return;
        int i=m-1,j=n-1;
        int k=m+n;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k-1]=nums1[i];
                i--;
            }else{
                nums1[k-1]=nums2[j];
                j--;
            }
            k--;
        }
        if(j>=0){
            for(int k=0;k<=j;k++)
                nums1[k]=nums2[k];
        }
    }
};


int main(){

    Solution ans;
    int m,n,score;
    cin >> m >> n;
    int M,N=n,i=0;
    cin >> M;
    vector<int>a(m,0);
    vector<int>b;
    while(i<M){
        cin >> a[i];
        i++;
    }
    while(N--){
        cin >> score;
        b.push_back(score);
    }
    ans.merge(a,M,b,n);
    for(auto i:a)
        cout << i << endl;
    return 0;
}