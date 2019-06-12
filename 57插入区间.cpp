#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        if(intervals.empty()){res.push_back(newInterval);return res;}
        if(newInterval.empty())return intervals;
        int len=intervals.size();
        if(newInterval[0]>intervals[len-1][1]){intervals.push_back(newInterval);return intervals;}
        if(newInterval[1]<intervals[0][0]){intervals.insert(intervals.begin(),newInterval);return intervals;}
        int i=0,j=len-1;int posi=-1,posj=-1,posx=-1,posy=-1;
        while(i<=len && j>=0){
            if(intervals[i][0]<newInterval[0]){posi=i;posx=0;}
            if(intervals[i][1]<newInterval[0]){posi=i;posx=1;}
            if(intervals[j][1]>newInterval[1]){posj=j;posy=1;}
            if(intervals[j][0]>newInterval[1]){posj=j;posy=0;}
            i++;j--;   
        }
        //cout << posi <<' ' << posj<<' ' <<posx<<' ' <<posy << endl;
        if(posi==-1 && posj==-1)
            res.push_back(newInterval);

        if(posi==-1 && posj!=-1){
            int i=0;
            if(posy==1){vector<int>tmp(2);tmp[0]=newInterval[0];tmp[1]=intervals[posj][1];res.push_back(tmp);i=posj;}
            if(posy==0){vector<int>tmp(2);tmp[0]=newInterval[0];tmp[1]=newInterval[1];res.push_back(tmp);i=posj;}
            while(i<len){
                if(i==posj &&posy==1)
                    {i++;continue;}
                res.push_back(intervals[i]);
                i++;
            }            
        }
        
        if(posi!=-1 && posj==-1){
            int i=0;
            while(i<=posi){
                if(i==posi &&posx==0)
                    break;
                res.push_back(intervals[i]);
                i++;
            } 
            if(posx==1){vector<int>tmp(2);tmp[0]=newInterval[0];tmp[1]=newInterval[1];res.push_back(tmp);}
            if(posx==0){vector<int>tmp(2);tmp[0]=intervals[posi][0];tmp[1]=newInterval[1];res.push_back(tmp);}
        }

        if(posi!=-1 && posj!=-1){
            for(int i=0;i<len;i++){
                if(i==posi && posx==0){
                    if(posy==0){vector<int>tmp(2);tmp[0]=intervals[posi][0];tmp[1]=newInterval[1];res.push_back(tmp);i=posj;}
                    if(posy==1){vector<int>tmp(2);tmp[0]=intervals[posi][0];tmp[1]=intervals[posj][1];res.push_back(tmp);i=posj;}
                }
                if(i==posi && posx==1){
                    res.push_back(intervals[i]);
                    if(posy==0){vector<int>tmp(2);tmp[0]=newInterval[0];tmp[1]=newInterval[1];res.push_back(tmp);i=posj;}
                    if(posy==1){vector<int>tmp(2);tmp[0]=newInterval[0];tmp[1]=intervals[posj][1];res.push_back(tmp);i=posj;}
                }
                if(i==posj &&posy==1)
                    continue;
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
    
};

int main(){

    Solution ans;
    int m,a,b;
    cin >> m;
    vector<vector<int> >g(m,vector<int>(2));
    vector<int>t(2);
    for(int i=0;i<m;i++)
        for(int j=0;j<2;j++)
            cin >> g[i][j];
    for(int i=0;i<2;i++)
        cin >> t[i];
    
    for(auto i:ans.insert(g,t)){
        for(auto j:i)
            cout << j <<" ";
        cout << '\n';
    }
    return 0;
}