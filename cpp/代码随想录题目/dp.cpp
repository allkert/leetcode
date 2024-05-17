# include<iostream>
# include<vector>
# include<numeric>
# include<string>
#include <unordered_map>
#include <map>
#include <math.h>
#include<algorithm>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};

class SolutionKama{
public:

    // 46. 携带研究材料（第六期模拟笔试）
    int KaMa_46(){
        int m, n;
        cin >> m;
        cin >> n;
        vector<int> weight(m);
        vector<int> value(m);
        for(int i = 0; i < m; i++){
            cin >> weight[i];
        }
        for(int i = 0; i < m; i++){
            cin >> value[i];
        }
        vector<int> dp(n+1);
        for(int i = weight[0]; i <= n; i++){
            dp[i] = value[0];
        }
        for(int epoch = 1; epoch < m; epoch++){
            for(int j = n; j > 0; j--){
                if(j >= weight[epoch]){
                    dp[j] = max(dp[j-weight[epoch]]+value[epoch], dp[j]);
                }
            }
        }
        cout << *dp.rbegin() << endl;
        return 1;
    }

    // 52. 携带研究材料（第七期模拟笔试）
    int kama52(){
        int m, n;
        cin >> m;
        cin >> n;
        vector<int> weight(m);
        vector<int> value(m);
        for(int i = 0; i < m; i++){
            cin >> weight[i];
            cin >> value[i];
        }
        vector<int> dp(n+1);
        for(int i = 1; i <= n; i++){
            dp[i] = value[0]*(i / weight[0]);
        }
        for(int i = 1; i < m; i++){
            for(int j = weight[i]; j <= n; j++){
                dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
            }
        }
        cout << dp[n] << endl;
        return 1;
    }

    int kama57(){
        int n, m;
        cin >> n;
        cin >> m;
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(j <= i) dp[i] += dp[i-j];
            }
        }
        cout << dp[n] << endl;
        return 1;
    }

    // 多重背包问题
    int kama56(){
        int C, N;
        cin >> C;
        cin >> N;
        vector<int> w(N), v(N), k(N);
        for(int i = 0; i < N; i++) cin >> w[i];
        for(int i = 0; i < N; i++) cin >> v[i];
        for(int i = 0; i < N; i++) cin >> k[i];
        vector<int> dp(C+1);
        for(int i = 0; i < N; i++){
            for(int j = C; j >= w[i]; j--){
                for(int u = 0; u < k[i] && (u+1)*w[i] <= j; u++){
                    dp[j] = max(dp[j], dp[j-(u+1)*w[i]] + (u+1)*v[i]);
                }       
            }
        }
        cout << dp[C] << endl;
        return 1;
    }

};

class Solution{
public:

    // 509 斐波那契数
    int fib(int n) {
        if(n <= 1) return n;
        int dp[2] = {0, 1};
        int tmp;
        for(int i = 1; i < n; i++){
            tmp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }

    // 70 爬楼梯
    int climbStairs(int n) {
        if(n <= 2) return n;
        int dp[2] = {1, 2};
        int tmp;
        for(int i = 3; i <= n; i++){
            tmp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }

    // 746. 使用最小花费爬楼梯
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2] = {0, 0};
        for(int n = 2; n <= cost.size(); n++){
            int tmp = min(dp[0] + cost[n-2], dp[1] + cost[n-1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }

    // 62. 不同路径
    int uniquePaths(int m, int n) {
        int dp[n];
        for(int i = 0; i < n; i++) dp[i] = 1;
        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                dp[col] += dp[col-1];
            }
        }
        return dp[n-1];
    }

    // 63. 不同路径 II
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> dp(obstacleGrid[0].size(), 0);
        for(int i = 0; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i] == 0){
                dp[i] = 1;
            }
            else break;
        }
        for(int i = 1; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 1) dp[0] = 0;
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] += dp[j-1];
            }
        }
        return *dp.rbegin();
    }

    // 343 整数拆分
    int integerBreak(int n) {
        if(n <= 2) return 1;
        if(n == 3) return 2;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i <= n; i++){
            for(int j = 1; j <= i/2; j++){
                dp[i] = max(dp[i], dp[j]*dp[n-j]);
            }
        }
        return *dp.crbegin();
    }

    // 96. 不同的二叉搜索树
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];                
            }
        }
        return dp[n];
    }

    // 416 分割等和子集
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int bagSize = sum / 2;
        vector<int> dp(bagSize + 1);
        for(int i = nums[0]; i <= bagSize; i++){
            dp[i] = nums[0];
        }
        for(int i = 1; i < nums.size(); i++){
            for(int j = bagSize; j > 0; j--){
                if(j >= nums[i]){
                    dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
                }
            }
        }
        if(*dp.rbegin() == bagSize) return true;
        return false;
    }


    // 1049. 最后一块石头的重量 II
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int bagSize = total/2;
        vector<int> dp(bagSize + 1);
        for(int i = stones[0]; i <= bagSize; i++){
            dp[i] = stones[0];
        }
        for(int i = 1; i < stones.size(); i++){
            for(int j = bagSize; j > 0; j--){
                if(j >= stones[i]){
                    dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
                }
            }
        }
        return total - 2*(*dp.rbegin());
    }


    // 494. 目标和
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> pre;
        unordered_map<int, int> cur;
        pre[nums[0]]++;
        pre[-nums[0]]++;
        for(int i = 1; i < nums.size(); i++){
            for(auto it: pre){
                cur[it.first + nums[i]] += it.second;
                cur[it.first - nums[i]] += it.second;
            }
            swap(cur, pre);
            cur.clear();
        }
        return pre[target];
    }

    // 背包问题的思路
    int findTargetSumWaysBagSolution(vector<int>& nums, int target){
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum + target) % 2 != 0) return 0;
        if(abs(target) > sum) return 0;
        int bagSize = (sum + target)/2;
        vector<int> dp(bagSize + 1);
        dp[0] = 1;
        if(nums[0] <= bagSize){
            dp[nums[0]]++;
        }
        for(int i = 1; i < nums.size(); i++){
            for(int j = bagSize; j >= 0; j--){
                if(j >= nums[i]){
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return *dp.rbegin();
    }

    // 474 一和零
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(string str: strs){
            int oneNum = 0, zeroNum = 0;
            for(char ch: str){
                if(ch == '1') oneNum++;
                else zeroNum++;
            }
            for(int i = m; i >= zeroNum; i--){
                for(int j = n; j >= oneNum; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-oneNum]+1);
                }
            }
        }
        return dp[m][n];
    }

    // 518. 零钱兑换 II
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }


    // 377 组合总和Ⅳ 
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) { // 遍历背包
            for (int j = 0; j < nums.size(); j++) { // 遍历物品
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }

    // 322. 零钱兑换
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                if(dp[j-coins[i]] != INT_MAX){
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
                }
            }
        }
        return (dp[amount] == INT_MAX)? -1:dp[amount];
    }

    // 279. 完全平方数
    int numSquares(int n) {
        int itemSize = pow(n, 0.5);
        vector<int> item(itemSize);
        for(int i = 0; i < itemSize; i++){
            item[i] = (i+1)*(i+1);
        }
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < itemSize; i++){
            for(int j = item[i]; j <= n; j++){
                if(dp[j] - item[i] != INT_MAX){
                    dp[j] = min(dp[j], 1 + dp[j-item[i]]);
                }
            }
        }
        return dp[n];
    }

    // 参考答案很简洁，而且不需要判断if(dp[j] - item[i] != INT_MAX)
    // 因为有1存在，所以前面的不可能为INT_MAX
    int numSquares_ref(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) { // 遍历物品
            for (int j = i * i; j <= n; j++) { // 遍历背包
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];
    }

    // 139. 单词拆分
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.length()];
    }


    // 198 打家劫舍
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int dp[2] = {nums[0], nums[1] > nums[0]? nums[1] : nums[0]};
        int tmp;
        for(int i = 2; i < nums.size(); i++){
            tmp = max(dp[0] + nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }

    // 213. 打家劫舍 II
    int rob2(vector<int>& nums) {
        // 对于第一家有两个选择， 偷或者不偷，如果不偷，则用nums[1:end]进行非环形的打家劫舍
        // 如果偷,则按照nums[2]到nums[end-1]
        return max(nums[0] + rob213(nums, 2, nums.size()-2), rob213(nums, 1, nums.size()-1));
    }

    int rob213(vector<int>& nums, int begin, int end){
        if(begin > end) return 0;
        if(begin == end) return nums[begin];
        int dp[2] = {nums[begin], nums[begin+1] > nums[begin]? nums[begin+1] : nums[begin]};
        int tmp;
        for(int i = begin + 2; i <= end; i++){
            tmp = max(dp[0] + nums[i], dp[1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }


    // 337. 打家劫舍 III
    // 暴力递归的方法,超时超时辣
    int rob3(TreeNode* root) {
        if(root == NULL) return 0;
        int robChild = rob3(root->left) + rob3(root->right);
        int leftRob = 0, rightRob = 0;
        if(root->left != NULL) leftRob  = rob3(root->left->left)  + rob3(root->left->right);
        if(root->right!= NULL) rightRob = rob3(root->right->left) + rob3(root->right->right);
        return max(robChild, root->val + leftRob + rightRob); 
    }

    // dp方法
    int robTree(TreeNode* root){
        vector<int> res = robTraversal(root);
        return max(res[0], res[1]);
    }
    vector<int> robTraversal(TreeNode* root){
        if(root == NULL) return {0, 0};
        vector<int> left = robTraversal(root->left);
        vector<int> right = robTraversal(root->right);
        return {max(left[0], left[1]) + max(right[0], right[1]), root->val + left[0]+ right[0]};
    }


    // 121 买卖股票的最佳时机
    // 贪心的方法
    int maxProfit_greedy(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int buyin = prices[0];
        int maxp = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < buyin) buyin =prices[i];
            else maxp = max(maxp, prices[i] - buyin);
        }
        return maxp;
    }

    int maxProfit_dp(vector<int>& prices){
        int dp[2] = {0, -prices[0]};
        for(int i = 1; i < prices.size(); i++){
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(dp[1], -prices[i]);
        }
        return dp[0];
    }

    // 122. 买卖股票的最佳时机 II
    int maxProfit2(vector<int>& prices) {
        int dp[2] = {0, -prices[0]};
        int tmp;
        for(int i =1; i < prices.size(); i++){
            tmp = max(dp[1] + prices[i], dp[0]);
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[0] = tmp;
        }
        return dp[0];
    }

    // int maxProfit3(vector<int>& prices) {
        
    // };

    int maxProfit4(int k, vector<int>& prices) {
        vector<vector<int>> dp(k + 1, vector<int>(2));
        vector<vector<int>> tmp(k + 1, vector<int>(2));
        for(int i = 0; i <= k; i++) dp[i][0] = -prices[0];
        tmp = dp;
        for(int i = 1; i < prices.size(); i++){
            tmp[0][0] = max(-prices[i], tmp[0][0]);
            for(int j = 1; j <= k; j++){
                tmp[j][0] = max(dp[j][0], dp[j][1] - prices[i]);
                tmp[j][1] = max(dp[j][1], dp[j-1][0] + prices[i]);
            }
            dp = tmp;
        }
        return dp[k][1];
    }

    // 123. 买股票的最佳时机Ⅲ
    int maxProfit3_ref(vector<int>& prices){
        vector<int> dp{-prices[0], 0, -prices[0], 0};
        for(int i = 1; i < prices.size(); i++){
            dp[3] = max(dp[3], dp[2] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[0] = max(dp[0], -prices[i]);
        }
        return dp[3];
    }

    // 188. 买卖股票的最佳时机 IV
    int maxProfit4_ref(int k, vector<int>& prices){
        vector<int> dp(2*k+1);
        for(int i = 0; i < k; i++){
            dp[2*i+1] = -prices[0];
            dp[2*i+2] = 0;
        }
        for(int i = 1; i < prices.size(); i++){
            for(int j = 0; j < k; j++){
                dp[2*j+1] = max(dp[2*j+1], dp[2*j] - prices[i]);
                dp[2*j+2] = max(dp[2*j+2], dp[2*j+1] + prices[i]);
            }
        }
        return dp[2*k];
    }

    // 309. 买卖股票的最佳时机含冷冻期
    int maxProfit_frozen(vector<int>& prices) {
        vector<int> dp = {-prices[0], 0, 0};
        vector<int> tmp(dp);
        for(int i = 1; i < prices.size(); i++){
            tmp[0] = max(dp[0], dp[2] - prices[i]);
            tmp[1] = dp[0] + prices[i];
            tmp[2] = max(dp[2], dp[1]);
            dp = tmp;
        }
        return max(dp[0], max(dp[1], dp[2]));
    }

    // 714. 买卖股票的最佳时机含手续费
    int maxProfit_Fee(vector<int>& prices, int fee){
        vector<int> dp{-prices[0]-fee, 0};
        int tmp;
        for(int i = 1; i < prices.size(); i++){
            tmp = max(dp[0], dp[1] - prices[i] - fee);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[0] = tmp;
        }
        return dp[1];
    }

    // 300. 最长递增子序列
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }

    // 674. 最长连续递增序列
    // 贪心
    int findLengthOfLCIS_greedy(vector<int>& nums) {
        int res = 1;
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                count++;
                res = max(count, res);

            }
            else{
                count = 1;
            }
        }
        return res;
    }

    // dp,写出来好像和贪心一个意思哈哈哈哈哈哈哈哈哈哈
    int findLengthOfLCIS_dp(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int dp = (nums[1] > nums[0])? 2:1;
        int res = dp;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                dp = dp + 1;
                res = max(dp, res);
            }
            else dp = 1;
        }
        return res;
    }

    // 718. 最长重复子数组
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            if(nums1[i] == nums2[0]){
                dp[i][0] = 1;
                res = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(nums1[0] == nums2[i]){
                dp[0][i] = 1;
                res = 1;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }

    // 1035. 不相交的线
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));
        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
                }
                if(dp[i][j] > res) res = dp[i][j];
            }
        }
        return res;
    }

    // 1143. 最长公共子序列
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1));
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }

    // 53. 最大子数组和
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp = max(nums[i], dp + nums[i]);
            if(res < dp) res = dp;
        }
        return res;
    }

    // 392. 判断子序列
    // 两个指针即可。
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(int j = 0; j < t.size()&&i < s.size(); j++){
            if(s[i] == t[j]) i++;
            cout << i  << j << endl;
        }
        return(i == s.size());
    }

    bool isSubsequence_DP(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }


    // 115. 不同的子序列
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1));
        long long m = 10e9 + 7;
        for (int i = 0; i <= s.size(); i++)
            dp[0][i] = 1;
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (s[j - 1] == t[i - 1])
                    dp[i][j] = (((long)dp[i][j - 1]) + dp[i - 1][j - 1]) % m;
                else
                    dp[i][j] = ((long)dp[i][j - 1]) % m;
            }
        }
        return dp[t.size()][s.size()];
    }


    // 583. 两个字符串的删除操作
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for(int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for(int j = 1; j <= word2.size(); j++) dp[0][j] = j;
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+2));
            }
        }
        return dp[word1.size()][word2.size()];
    }

    // 72. 编辑距离
    int editDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for(int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for(int j = 1; j <= word2.size(); j++) dp[0][j] = j;
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }
        return dp[word1.size()][word2.size()];
    }

    // 647. 回文子串
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    if(j - i == 1) dp[i][j] = 2;
                    else if(dp[i+1][j-1] == 0) dp[i][j] = 0;
                    else dp[i][j] = dp[i+1][j-1] + 2;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j] > 0) count++;
            }
        }
        return count;
    }

    int countSubstringsRef(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) { // 情况一 和 情况二
                        result++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 情况三
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }

    // 516. 最长回文子序列
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if (s[i] == s[j]){
                    if (j - i <= 1) dp[i][j] = j - i + 1;
                    else dp[i][j] = dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }



};


int main(){
    Solution s;
    vector<int> prices{3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << s.countSubstrings("fdsklf");
}
