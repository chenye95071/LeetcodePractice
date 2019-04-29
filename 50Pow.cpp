/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]

*/





#include <iostream>
using namespace std;


class Solution {
public:
    double myPow(double x, long n) {
/*        if(n > 2147483647/10 )
            n=__INT_MAX__;
        if(n <-2147483647/10)
            n=-__INT_MAX__ -1;*/
        double ans=1.0;
        double base=x;
        if(n==0)
            return 1;
        else if (n<0) {
            base=1.0/base;
            n=-n;
            cout << base << " " << n <<endl;
        }
        while(n !=0){
            if (n&1 !=0)
                ans*=base;
            base*=base;
            n=n>>1;
        }
    return ans;
    }
        
};



int main(){
	Solution ans;
    double a;int b;
	cin >> a >> b;
	cout << ans.myPow(a,b) <<endl;
}