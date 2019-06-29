#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
private:
    double calc(vector<int>s,int x1,int x2,int y1,int y2){
        double min=__INT_MAX__;
        int sx,sy;
        for(int i=0;i<s.size();i++){
            if(i%2==0){sx=s[i];continue;}
            if(i%2==1)sy=s[i];
            double d1=pow((x1-sx)*(x1-sx)+(y1-sy)*(y1-sy),0.5);
            double d2=pow((x2-sx)*(x2-sx)+(y2-sy)*(y2-sy),0.5);
            double D=d1*d2;
            if(D<min)min=D;
        }
        return min;
    }
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        map<vector<double>,vector<int>>T;
        double S=__INT_MAX__;
        for(int i=0;i<points.size();i++){
            for(int j=i;j<points.size();j++){
                int x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                int X=x1-x2,Y=y1-y2;
                double l=pow((X*X+Y*Y),0.5);
                double midX=(x1+x2)/2.0,midY=(y1+y2)/2.0;
                vector<double>tmp={l,midX,midY};
                if(T.find(tmp)!=T.end()){
                    double s=calc(T[tmp],x1,x2,y1,y2);
                    T[tmp].push_back(x1);
                    T[tmp].push_back(y1);
                    if(s<S)S=s;
                }else{
                    T[tmp]={x1,y1};
                }
            }
        }
        if(S==__INT_MAX__)
            S=0;
        return S;
    }
};

int main(){

    Solution ans;
    int m,n;
    cin >> m;
    vector<vector<int> >g(m,vector<int>(2));
    for(int i=0;i<m;i++)
        for(int j=0;j<2;j++)
            cin >> g[i][j];

    cout << ans.minAreaFreeRect(g) << endl;
    return 0;
}


