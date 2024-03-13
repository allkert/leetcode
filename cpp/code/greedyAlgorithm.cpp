# include<iostream>
# include<vector>
# include<limits>
# include <algorithm>

using namespace std;

class Solution {
public:

    // 455. 分发饼干
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for(int i = g.size()-1, index = s.size()-1; i >= 0 && index >= 0; i--){
            if(s[index] >= g[i]){
                res++;
                index--;
            }
        }
        return res;
    }

    // 376 摆动序列
    int wiggleMaxLength_dp(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int dp[2] = {1, 1};
        int res = 2;
        if(nums[1] > nums[0]) dp[0] = 2;
        else if(nums[1] < nums[0]) dp[1] = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                dp[0] = max(dp[0], dp[1] + 1);
            }
            else if(nums[i] < nums[i-1]){
                dp[1] = max(dp[1],dp[0] + 1);
            }
        }
        return (dp[0] > dp [1])? dp[0]:dp[1];
    }

    int wiggleMaxLength_dp(vector<int>& nums){
        if(nums.size() == 1) return 1;
        int preDif = 0;
        int curDif = 0;
        int res = 1;
        for(int i = 0; i < nums.size()-1; i++){
            curDif = nums[i+1]-nums[i];
            if((preDif <= 0 && curDif > 0) || (preDif >= 0 && curDif < 0)){
                preDif = curDif;
                res++;
            }
        }
        return res;
    }

    // 53 最大子数组和
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            if(count > res) res = count;
            if(count < 0) count = 0;
        }
        return res;
    }

    // 122. 买卖股票的最佳时机 II
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i+1]-prices[i] > 0) res += prices[i+1]-prices[i];
        }
        return res;
    }

    int maxProfit_dp(vector<int>& prices){
        int dp[2] = {0, -prices[0]};
        for(int i = 1; i < prices.size(); i++){
            int tmp0 = dp[0];
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(dp[1], tmp0 - prices[i]);    
        }
        return dp[0];
    }
};