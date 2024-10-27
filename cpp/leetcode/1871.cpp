#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n, false);
        dp[0] = true;
        for(int i = 1; i < minJump; ++i) dp[i] = false;
        int acc = 0;
        for(int i = minJump; i < n; ++i){
            // cout << i << ' ';
            int right = i - minJump, left = i - maxJump;
            // cout << left << right << ' ';
            acc += dp[right];
            // cout << "acc" << acc <<' ';
            if(left > 0) acc -= dp[left - 1];
            if(acc && s[i] == '0') dp[i] = true;
            // cout << "dp " << i << dp[i] << endl; 
        }
        return dp[n-1];
    }


};

int main(){
    auto s = "011010";
    auto sol = Solution();
    cout << sol.canReach(s, 2, 3) << endl;
}