class Solution {
public:
// 动态规划
    int jump1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(j + nums[j] >= i) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n-1];
    }

// 贪心
    int jump2(vector<int>& nums) {
        int res = 0, cur_right = 0, next_right = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            next_right = max(next_right, i + nums[i]);
            if(i == cur_right){
                cur_right = next_right;
                res++;
            }
        }
        return res;
    }
};