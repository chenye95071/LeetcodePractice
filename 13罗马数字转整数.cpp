#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int>T;
        int res=0,minus=0;
        T['I']=1;T['V']=5;T['X']=10;T['L']=50;T['C']=100;T['D']=500;T['M']=1000;
        for(int i=s.size()-1;i>=0;i--)
            res+=T[s[i]];
        if(s.size()>1)
            for(int i=1;i<s.size();i++)
                if(T[s[i]]>T[s[i-1]])
                    minus+=T[s[i-1]];
        //cout << res << ' ' << minus << endl;
        return res-2*minus;
    }
};


int main(){

    Solution ans;
    string s;
    cin >> s;
        
    cout << ans.romanToInt(s) << endl;
    return 0;
}