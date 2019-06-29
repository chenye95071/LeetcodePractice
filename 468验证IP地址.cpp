#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>
using namespace std;

class Solution {
private:
    vector<string> split(const string& s,const char flag = ' ') {
        vector<string> sv;
        istringstream iss(s);
        string temp;
        while (getline(iss, temp, flag))
            sv.push_back(temp);
        return sv;
    }
    bool ipv4Judge(string IP){
        vector<string>ip=split(IP,'.');
        if(ip.size()!=4)return false;
        for(auto i:ip){
            if(i.empty() ||i.size()>3)return false;
            if(i.size()>1 && i[0]=='0')return false;
            for(auto j:i)
                if(!isdigit(j))return false;
            if(stoi(i)>255 || stoi(i)<0)return false;
        }
        return true;
    }
    bool ipv6Judge(string IP){
        vector<string>ip=split(IP,':');
        if(ip.size()!=8)return false;
        for(auto i:ip){
            if(i.empty())return false;
            if(i.size()>4)return false;
            for(auto j:i)
                if(!isdigit(j)){
                    if(j<'A'||(j>'F'&&j<'a')||j>'f')
                        return false;
                }
        }
        return true;
    }
    int judge(string IP){
        if(ipv4Judge(IP))return 1;
        else if(ipv6Judge(IP))return 2;
        else return 0;
    }
public:
    string validIPAddress(string IP) {
        if(!isalnum(IP[0]) || !isalnum(IP[IP.size()-1]))return "Neither";
        switch (judge(IP)){
            case 1:return "IPv4";break;
            case 2:return "IPv6";break;
            default:return "Neither";break;
        }
    }
};

int main(){
    Solution ans;
    string n;
    cin >> n;
    cout << ans.validIPAddress(n) << endl ;
    // for(auto i:split(n,'.'))
    //     cout << i << endl;
    return 0;
}